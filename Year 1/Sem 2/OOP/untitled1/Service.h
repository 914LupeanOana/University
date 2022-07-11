//
// Created by Oana Lupean on 10.03.2022.
//

#ifndef UNTITLED1_SERVICE_H
#define UNTITLED1_SERVICE_H

#include "Country_Repository.h"
#include <stdbool.h>

typedef struct
{
    CountryRepo* repo;
} service;

service* createService(CountryRepo* repo);
CountryRepo * get_repository(service* service);


void add_to_service(service *service, char *name, char *continent, double population);

bool delete_from_service(service *service, char *name, char *continent, double population);

bool update_population_of_country(service *service, char *name, char *continent, double new_population);

int search_for_country(service *service, char *name);

dynamic_array* search_by_string_service(service *service, char* string);

dynamic_array* search_by_continent_over_a_given_population(service *offer_service, int type_option, double population);

dynamic_array* filter_countries_with_given_property(service *cservice, bool (*property)(Country *), double population);

int* get_country_count_from_service(service *serv);

void sort_ascending_by_population(dynamic_array * offer_data);

Country ** get_data_from_service(service *cservice);

dynamic_array* get_list_of_countries_from_service(service *cservice);

history_array* get_history(service *cervice);

bool undo_service(service *cservice);

bool redo_service(service *cservice);

void deallocate_service(service *cservice);

#endif //UNTITLED1_SERVICE_H

