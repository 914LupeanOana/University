//
// Created by Oana Lupean on 23.03.2022.
//

#ifndef A3_4_DYNAMIC_ARRAY_H
#define A3_4_DYNAMIC_ARRAY_H

#include "domain.h"

typedef Country TElem;


/// The structure holds:
/// an array of pointers to offer instances.
/// the length of this collection.
/// the maximum capacity.
typedef struct{
    TElem ** data;
    int length;
    int capacity;
} dynamic_array;

dynamic_array* create_dynamic_array();

void add(dynamic_array* current_list, TElem* new_element);

void delete_(dynamic_array* array, int position);

void update(dynamic_array* current_countries, int position, TElem* updated_element);

void resize(dynamic_array* array, int new_capacity);

void deallocate_array(dynamic_array* array);

#endif //A3_4_DYNAMIC_ARRAY_H
