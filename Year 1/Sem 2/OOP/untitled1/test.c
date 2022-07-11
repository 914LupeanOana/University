//
// Created by Oana Lupean on 24.03.2022.
//

#include "test.h"
#include "country.h"
#include "Service.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void test_create_country(){

    Country * p = createCountry("Romania", "Europa",  2);
    assert(p != NULL);
    free(p);
}
void test_getters_of_country(){
    Country * p = createCountry("Romania", "Europa",  2);

    char *name = getName(p);
    assert(strcmp(name, "Romania")==0);

    char* continent = getContinent(p);
    assert(strcmp(continent, "Europa")==0);

    double population = getPopulation(p);
    assert(population == 2);

    free(p);
}

void test_setters(){
    Country * p = createCountry("Romania", "Europa",  2);

    set_population(p, 10);
    double new_pop= getPopulation(p);
    assert(new_pop == 10);


    free(p);
}

void test_add(){
    CountryRepo * repo = createRepo();
    service * serv = createService(repo);
    char* name = "Italia";
    char* continent = "Europa";
    double population = 7;
    add_to_service(serv, name, continent, population);
    int* country_count = get_country_count_from_service(serv);
    assert(*country_count == 1);
    deallocate_service(serv);
}

void test_delete(){
    CountryRepo * repo = createRepo();
    service * serv = createService(repo);
    char* name = "Italia";
    char* continent = "Europa";
    double population = 7;
    add_to_service(serv, name, continent, population);
    bool deletion_result = delete_from_service(serv, name, continent, population);
    assert(deletion_result == true);
    char* name1 = "Romania";
    deletion_result = delete_from_service(serv, name, continent, population);
    assert (deletion_result == false);

    deallocate_service(serv);
}

void test_update(){
    CountryRepo * repo = createRepo();
    service * serv = createService(repo);
    char* name = "Italia";
    char* continent = "Europa";
    double population = 7;
    add_to_service(serv, name, continent, population);
    double new_population = 3;
    bool updated_result = update_population_of_country(serv, name, continent, new_population);
    assert(updated_result == true);

    deallocate_service(serv);
}

void test_search(){
    CountryRepo * repo = createRepo();
    service * serv = createService(repo);
    char* name = "Italia";
    char* continent = "Europa";
    double population = 7;
    add_to_service(serv, name, continent, population);
    int search_result = search_for_country(serv, name);
    assert(search_result != -1);
    char* name1 = "Romania";
    search_result = search_for_country(serv, name1);
    assert(search_result == -1);

    deallocate_service(serv);
}

void test_search_by_string(){
    CountryRepo * repo = createRepo();
    service * serv = createService(repo);
    char* name = "Italia";
    char* continent = "Europa";
    double population = 7;
    add_to_service(serv, name, continent, population);
    char* search_string = "a";
    dynamic_array* resulted_countries = search_by_string_service(serv, search_string);
    assert(resulted_countries->length == 1);
    deallocate_dynamic_array(resulted_countries);
    deallocate_service(serv);
}

void test_undo_redo(){
    CountryRepo * repo = createRepo();
    service * serv = createService(repo);
    char* name = "Italia";
    char* continent = "Europa";
    double population = 7;
    add_to_service(serv, name, continent, population);
    int* country_count = get_country_count_from_service(serv);
    assert(*country_count == 1);

    undo_service(serv);
    assert(*country_count == 0);

    redo_service(serv);
    assert(*country_count == 1);
}

void run_tests(){
    test_create_country();
    test_getters_of_country();
    test_setters();
    test_add();
    test_delete();
    test_update();
    test_search();
    test_search_by_string();
    test_undo_redo();
}