//
// Created by Oana Lupean on 23.03.2022.
//

#ifndef A3_4_REPOSITORY_H
#define A3_4_REPOSITORY_H

#include "dynamic_array.h"

typedef struct{
    dynamic_array** past_lists;
    int index_of_current_list;
    int length_of_history;
}history_array;


typedef struct {
    dynamic_array* list_of_countries;
    history_array history_of_states;
}CountryRepo;

CountryRepo * createRepo();

Country ** get_data(CountryRepo * repo);

int* get_countires_count(CountryRepo* repo);

int* get_capacity(CountryRepo* repo);

dynamic_array* get_list_of_countries(CountryRepo* repo);

history_array* get_archive(CountryRepo* repo);

int* get_length_of_archive(CountryRepo* repo);

int* get_index_of_current_list_in_archive(CountryRepo* repo);

void add_to_repo(CountryRepo* repo, Country* new_country);

void delete_from_repo(CountryRepo* repo, int position);

void update_population_in_repo(CountryRepo* repo, int position, double new_population);

void add_current_list_to_history(CountryRepo* repo);

void resize_repository(CountryRepo* repo, int new_capacity);

void deallocate_repository(CountryRepo* repo);

void deallocate_dynamic_array(dynamic_array* country_array);

#endif //A3_4_REPOSITORY_H
