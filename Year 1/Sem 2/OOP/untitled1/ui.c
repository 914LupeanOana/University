//
// Created by Oana Lupean on 10.03.2022.
//
#include "ui.h"
#include "Country_Repository.h"
#include "Service.h"
#include <stdio.h>
#include <stdlib.h>

UI* createUI(service* s)
{
    UI* ui = malloc(sizeof(UI));
    if (ui == NULL)
        return NULL;
    ui->serv = s;

    return ui;
}

service* get_service(UI *ui){
    return ui->serv;
}

void printMenu()
{
    printf("\n**********************************************************\n");
    printf("1 - add a country.\n");
    printf("2 - list all countries.\n");
    printf("3 - delete a country.\n");
    printf("4 - update a country.\n");
    printf("5 - search by a string.\n");
    printf("6 - search by a continent, with population greater than a given value.\n");
    printf("7 - undo.\n");
    printf("8 - redo.\n");
    printf("9 - to exit.\n");
    printf("**********************************************************\n");
}



void print_all(UI *ui){

    service* serv = get_service(ui);
    int* country_count = get_country_count_from_service(serv);
    Country ** country_data = get_data_from_service(serv);

    for(int i=0;i<*country_count; i++){
        char string[100];
        toString(country_data[i], string);
        printf("%s", string);
        printf("\n");
    }
}

void add_country(UI *user_interface){
    char* name = (char*)malloc(sizeof(char) * 100);
    char* continent = (char*)malloc(sizeof(char) * 100);
    double population;
    printf("Name:");

    scanf("%s", name);

    printf("Continent:");
    scanf("%s", continent);

    printf("Population(millions):");
    scanf("%lf", &population);

    add_to_service(user_interface->serv, name, continent, population);
    printf("Country was added successfully.\n");

}

void delete(UI *user_interface){
    char* name = (char*)malloc(sizeof(char) * 100);
    char* continent = (char*)malloc(sizeof(char) * 100);
    double population;
    printf("Name:");

    scanf("%s", name);

    printf("Continent:");
    scanf("%s", continent);

    printf("Population(millions):");
    scanf("%lf", &population);

    bool result = delete_from_service(user_interface->serv, name, continent, population);
    if(result)
        printf("Country was deleted successfully.\n");
    else
        printf("There is no such country.\n");

}

void update_country(UI *user_interface){
    char* name = (char*)malloc(sizeof(char) * 100);
    char* continent = (char*)malloc(sizeof(char) * 100);
    double population;
    printf("Country:");
    scanf("%s", name);

    printf("Continent:");
    scanf("%s", continent);

    printf("Population(millions):");
    scanf("%lf", &population);


    printf("What do you want to do:\n");
    printf("\ta. Update\n");
    printf("\tb. Migrate\n");

    char user_option;
    scanf(" %c", &user_option);
    bool operation_result, operation_result1;

    if(user_option == 'a')
    {
        double new_population;
        printf("Population:");

        scanf("%lf", &new_population);
        operation_result = update_population_of_country(user_interface->serv, name, continent, new_population);
        if(operation_result)
            printf("The population was updated successfully.\n");
        else
            printf("The given country does not exist.\n");
    }

    else{
        if(user_option == 'b'){
            double emigrate_population, new_pop1, new_pop2;
            char* name1 = (char*)malloc(sizeof(char) * 100);
            char* continent1 = (char*)malloc(sizeof(char) * 100);
            double population1;
            printf("Emigrate an amount of people(millions): ");
            scanf("%lf", &emigrate_population);
            new_pop1 = population - emigrate_population;
            operation_result = update_population_of_country(user_interface->serv, name, continent, new_pop1);
            if (!operation_result)
                printf("The given country does not exist.\n");
            printf("To country: ");
            scanf("%s", name1);
            printf("From continent:");
            scanf("%s", continent1);
            printf("With population(millions):");
            scanf("%lf", &population1);
            new_pop2 = population1 + emigrate_population;
            operation_result1 = update_population_of_country(user_interface->serv, name1, continent1, new_pop2);
            if(operation_result)
                printf("The population migrated successfully.\n");
            else
                printf("The given country does not exist.\n");
        }
        else
            printf("Invalid option.\n");
    }

}

void search_by_string_ui(UI *user_interface) {
    char string[20];
    char empty[20];

    printf("Enter string:");
    scanf("%s", &string);


    dynamic_array *resulted_offers = search_by_string_service(user_interface->serv, string);

    if (resulted_offers->length > 0) {
        for (int i = 0; i < resulted_offers->length; i++) {
            char buffer_string[100];
            toString(resulted_offers->data[i], buffer_string);
            printf("%s", buffer_string);
            printf("%s", "\n");
        }
    } else
        printf("None of the offers match the given string.\n");

    deallocate_dynamic_array(resulted_offers);

}

void search_by_continent_ui(UI *user_interface){
    int continent;
    printf("Search by continent:\n");
    printf("\t1. Europe\n");
    printf("\t2. America\n");
    printf("\t3. Asia\n");
    printf("\t4. Africa\n");
    printf("\t5. Australia\n");
    scanf("%d", &continent);
    if(continent == 1 || continent == 2 || continent == 3|| continent == 4 || continent == 5){

        // read the departure date
        double population;
        printf("With population greater than:");
        scanf("%d", &population);


        dynamic_array* resulted_countries = search_by_continent_over_a_given_population(user_interface->serv, continent,
                                                                              population);
        if(resulted_countries->length > 0)
            for(int i=0; i < resulted_countries->length; i++){
                char buffer_string[100];
                toString(resulted_countries->data[i], buffer_string);
                printf("%s", buffer_string);
                printf("%s", "\n");
            }
        else
            printf("No countries match the given filters.\n");
        deallocate_dynamic_array(resulted_countries);
    }
    else
        printf("Invalid command.\n");

}

void undo(UI *user_interface){
    bool result = undo_service(user_interface->serv);
    if(result==true){
        printf("Undone.\n");
    }
    else
        printf("No more undo-s available.\n");
}

void redo(UI *user_interface){
    bool result = redo_service(user_interface->serv);
    if(result==true){
        printf("Redone.\n");
    }
    else
        printf("No more redo-s available.\n");
}

void start(UI *user_interface) {
    add_to_service(user_interface->serv,"Romania", "Europe", 142);
    add_to_service(user_interface->serv,"Italia", "Europe",  764);
    add_to_service(user_interface->serv,"Canada", "America",  8765);
    add_to_service(user_interface->serv,"Kongo", "Africa", 76);
    add_to_service(user_interface->serv,"India", "Asia",  87);
    add_to_service(user_interface->serv,"Japan", "Asia",  9876);
    add_to_service(user_interface->serv,"Greece", "Europe",  98);
    add_to_service(user_interface->serv,"Brazil", "America",  231);
    bool finished = false;
    int user_option = 0;
    while (!finished) {

        printMenu();
        printf("Enter option:");
        scanf("%d", &user_option);
        switch (user_option) {
            case 1: {
                add_country(user_interface);
                break;
            }
            case 2: {
                print_all(user_interface);
                break;
            }
            case 3: {
                delete(user_interface);
                break;
            }
            case 4: {
                update_country(user_interface);
                break;
            }
            case 5: {
                search_by_string_ui(user_interface);
                break;
            }
            case 6: {
                search_by_continent_ui(user_interface);
                break;
            }
            case 7: {
                undo(user_interface);
                break;
            }
            case 8: {
                redo(user_interface);
                break;
            }
            case 9: {
                printf("Bye!\n");
                finished = true;
                break;
            }

            default: {
                printf("Invalid command!\n");
                break;
            }
        }
    }
}

void deallocate_user_interface(UI *ui){
    deallocate_service(ui->serv);
    free(ui);
}