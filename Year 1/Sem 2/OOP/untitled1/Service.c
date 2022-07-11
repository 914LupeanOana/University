//
// Created by Oana Lupean on 10.03.2022.
//
#include "Service.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool is_Europe(Country* country){
    if (strcmp(getContinent(country), "Europa") == 0)
        return true;
    return false;
}

bool is_Asia(Country* country){
    if (strcmp(getContinent(country), "Asia") == 0)
        return true;
    return false;
}

bool is_America(Country* country){
    if (strcmp(getContinent(country), "America") == 0)
        return true;
    return false;
}

bool is_Africa(Country* country){
    if (strcmp(getContinent(country), "Africa") == 0)
        return true;
    return false;
}

bool is_Australia(Country* country){
    if (strcmp(getContinent(country), "Australia") == 0)
        return true;
    return false;
}

service* createService(CountryRepo *repo){
    service* cservice = (service*) malloc(sizeof(service));
    cservice->repo= repo;
    return cservice;
}

CountryRepo * get_repository(service* service){
    return service->repo;
}

int search_for_country(service *cservice, char* name){
    CountryRepo *repo = get_repository(cservice);
    Country ** country_data = get_data(repo);
    int* countries_count = get_countires_count(repo);

    for(int i=0; i<*countries_count; i++){
        char* current_name = getName(country_data[i]);

        if(strcmp(current_name, name)==0 )
            return i;
    }
    return -1;
}

void add_to_service(service *cservice, char *name, char *continent, double population){


    Country * country = createCountry(name, continent, population);
    add_to_repo(cservice->repo, country);
}

bool delete_from_service(service *cservice, char *name,char* continent, double population){


    int position = search_for_country(cservice, name);

    if(position == -1){
        return false;
    }
    else{
        delete_from_repo(cservice->repo, position);
        return true;
    }
}

bool update_population_of_country(service *cservice, char* name, char* continent, double new_population){

    int position = search_for_country(cservice, name);

    if(position == -1){
        return false;
    }
    else{
        update_population_in_repo(cservice->repo, position, new_population);
        return true;
    }
}

void sort_ascending_by_population(dynamic_array* country_data){
    int length = country_data->length;
    for(int i=0;i<length-1;i++)
        for(int j=i+1; j<length;j++)
            if(getPopulation(country_data->data[i]) > getPopulation(country_data->data[j]))
            {
                Country * aux = country_data->data[i];
                country_data->data[i] = country_data->data[j];
                country_data->data[j] = aux;
            }
}

dynamic_array* filter_countries_with_given_property(service *cservice, bool (*property)(Country *), double population){
    Country ** country_data = get_data(cservice->repo);
    int* country_count = get_countires_count(cservice->repo);

    dynamic_array* resulted_countries = (dynamic_array *)malloc(sizeof(dynamic_array));
    resulted_countries->data = (Country **)malloc(*country_count * sizeof(Country *));
    resulted_countries->length = 0;

    for(int i=0; i<*country_count; i++){
        double current_population = getPopulation(country_data[i]);
        if(property(country_data[i]) && (population <= current_population)){
            resulted_countries->data[resulted_countries->length] = country_data[i];
            resulted_countries->length++;
        }
    }
    return resulted_countries;
}

dynamic_array* search_by_string_service(service *serv, char* string){
    Country ** country_data = get_data(serv->repo);
    int* country_count = get_countires_count(serv->repo);

    dynamic_array* resulted_countries = (dynamic_array*)malloc(sizeof(dynamic_array));
    resulted_countries->data = (Country **)malloc(*country_count * sizeof(Country *));
    resulted_countries->length = 0;

    if(strcmp(string, "\n")==0){
        for(int i=0; i<*country_count; i++)
            resulted_countries->data[i] = country_data[i];
        resulted_countries->length = *country_count;
    }
    else {
        for (int i = 0; i < *country_count; i++) {
            char *name = getName(country_data[i]);
            if (strstr(name, string)) {
                resulted_countries->data[resulted_countries->length] = country_data[i];
                resulted_countries->length++;
            }
        }
    }

    return resulted_countries;
}


dynamic_array* search_by_continent_over_a_given_population(service * cservice, int continent_option, double population){

    dynamic_array* resulted_countries;

    bool (*property)(Country *);

    if(continent_option == 1)
        property = is_Europe;
    else {
        if (continent_option == 2)
            property = is_America;
        else {
            if (continent_option == 3)
                property = is_Asia;
            else {
                if (continent_option == 4)
                    property = is_Africa;
                else
                    property = is_Australia;

            }
        }
    }

    resulted_countries = filter_countries_with_given_property(cservice, property, population);

    sort_ascending_by_population(resulted_countries);

    return resulted_countries;
}

bool undo_service(service *cservice){
    int* index_of_current_list = get_index_of_current_list_in_archive(cservice->repo);
    if(*index_of_current_list == 0)
        return false;

    dynamic_array* current_list_of_countries = get_list_of_countries_from_service(cservice);
    history_array* history_list = get_history(cservice);
    dynamic_array* previous_list = history_list->past_lists[*index_of_current_list-1];

    if(previous_list->length > current_list_of_countries->capacity)
        resize_repository(cservice->repo, previous_list->length);

    for(int i=0; i<previous_list->length;i++)
        *current_list_of_countries->data[i] = *previous_list->data[i];
    current_list_of_countries->length = previous_list->length;

    *index_of_current_list = *index_of_current_list-1;

    return true;
}

bool redo_service(service *cservice){
    int* index_of_current_list = get_index_of_current_list_in_archive(cservice->repo);
    int* length_of_archive = get_length_of_archive(cservice->repo);
    if(*index_of_current_list == *length_of_archive-1)
        return false;


    dynamic_array* current_list_of_countries = get_list_of_countries_from_service(cservice);
    history_array* history_list = get_history(cservice);
    dynamic_array* anterior_list = history_list->past_lists[*index_of_current_list+1];

    if(anterior_list->length > current_list_of_countries->capacity)
        resize_repository(cservice->repo, anterior_list->length);

    for(int i=0; i<anterior_list->length;i++)
        *current_list_of_countries->data[i] = *anterior_list->data[i];
    current_list_of_countries->length = anterior_list->length;

    *index_of_current_list = *index_of_current_list+1;

    return true;
}

dynamic_array* get_list_of_countries_from_service(service *cservice){
    CountryRepo * repo = get_repository(cservice);
    return repo->list_of_countries;
}

Country ** get_data_from_service(service *cservice){
    CountryRepo * repo = get_repository(cservice);
    return get_data(repo);
}

history_array* get_history(service *cservice){
    CountryRepo * repo = get_repository(cservice);
    return get_archive(repo);
}

void deallocate_service(service *cservice){
    deallocate_repository(cservice->repo);
    free(cservice);
}

int* get_country_count_from_service(service *serv){
    CountryRepo * repo = get_repository(serv);
    return get_countires_count(repo);
}