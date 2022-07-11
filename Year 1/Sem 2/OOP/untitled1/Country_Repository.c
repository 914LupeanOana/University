//
// Created by Oana Lupean on 09.03.2022.
//
#include "Country_Repository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

CountryRepo* createRepo()
{
    CountryRepo *repo = (CountryRepo *)malloc(sizeof(CountryRepo));
    repo->list_of_countries = create_dynamic_array();


    repo->history_of_states.past_lists = (dynamic_array**)malloc(20 * sizeof(dynamic_array));
    repo->history_of_states.index_of_current_list = -1;
    repo->history_of_states.length_of_history = 0;



    add_current_list_to_history(repo);

    return repo;
}

void add_current_list_to_history(CountryRepo * repo){
    int *length = get_countires_count(repo);
    int *capacity = get_capacity(repo);
    Country** current_list_of_countries = get_data(repo);
    history_array* archive = get_archive(repo);
    int* length_of_archive = get_length_of_archive(repo);
    int* index_of_current_list = get_index_of_current_list_in_archive(repo);

    dynamic_array* copy_of_current_list = (dynamic_array*)malloc(sizeof(dynamic_array));
    copy_of_current_list->data = (Country**)malloc(repo->list_of_countries->length * sizeof(Country *));
    for(int i=0; i<*length; i++){
        copy_of_current_list->data[i] = (Country*)malloc(sizeof(Country));
        *copy_of_current_list->data[i] = *current_list_of_countries[i];
    }
    copy_of_current_list->length = *length;
    copy_of_current_list->capacity = *capacity;


    //deallocate what comes after the current list
    for(int index = *index_of_current_list + 1; index<*length_of_archive; index++){
        for(int offer=0; offer < archive->past_lists[index]->length;offer++)
            free(archive->past_lists[index]->data[offer]);
        free(archive->past_lists[index]->data);
    }


    // actually add to the history
    archive->past_lists[*index_of_current_list + 1] = copy_of_current_list;
    *index_of_current_list = *index_of_current_list + 1;
    *length_of_archive = *index_of_current_list + 1;
}

dynamic_array* get_list_of_countries(CountryRepo * repo){
    return repo->list_of_countries;
}

Country ** get_data(CountryRepo * repo){
    return repo->list_of_countries->data;
}

int* get_countires_count(CountryRepo * repo){
    return &repo->list_of_countries->length;
}

int* get_capacity(CountryRepo * repo){
    return &repo->list_of_countries->capacity;
}

history_array* get_archive(CountryRepo * repo){
    return &repo->history_of_states;
}

int* get_length_of_archive(CountryRepo * repo){
    return &repo->history_of_states.length_of_history;
}

int* get_index_of_current_list_in_archive(CountryRepo* repo){
    return &repo->history_of_states.index_of_current_list;
}

void add_to_repo(CountryRepo * repo, Country * new_country){
    dynamic_array* current_list = get_list_of_countries(repo);
    add(current_list, new_country);
    add_current_list_to_history(repo);
}

void delete_from_repo(CountryRepo * repo, int position){
    dynamic_array* current_list = get_list_of_countries(repo);
    delete_(current_list, position);
    add_current_list_to_history(repo);
}

void update_population_in_repo(CountryRepo * repo, int position, double new_population){
    dynamic_array* current_list = get_list_of_countries(repo);
    Country* updated_country = (Country*)malloc(sizeof(Country));
    *updated_country = *current_list->data[position];
    set_population(updated_country, new_population);

    update(current_list, position,
           updated_country);

    add_current_list_to_history(repo);
}

void resize_repository(CountryRepo * repo, int new_capacity){
    dynamic_array* current_list_of_countries = get_list_of_countries(repo);
    resize(current_list_of_countries, new_capacity);

}

void deallocate_repository(CountryRepo * repo){
    dynamic_array* current_list = get_list_of_countries(repo);
    deallocate_array(current_list);

    //free the history
    history_array* history = get_archive(repo);
    for(int list=0; list<history->length_of_history; list++){
        for(int offer_index=0; offer_index < history->past_lists[list]->length; offer_index++)
            free(history->past_lists[list]->data[offer_index]);
        free(history->past_lists[list]->data);
        free(history->past_lists[list]);
    }
    free(history->past_lists);

    free(repo);

}

void deallocate_dynamic_array(dynamic_array* country_array){
    free(country_array->data);
    free(country_array);
}


