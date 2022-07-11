//
// Created by Oana Lupean on 10.03.2022.
//

#ifndef UNTITLED1_UI_H
#define UNTITLED1_UI_H


#include "Service.h"
#include "Country_Repository.h"


typedef struct
{
    service* serv;
} UI;

UI* createUI(service *serv);

void add_country(UI *user_interface);

void delete(UI *user_interface);

void update_country(UI *user_interface);

void search_by_string_ui(UI *user_interface);

void search_by_continent_ui(UI *user_interface);

void undo(UI *user_interface);

void redo(UI *user_interface);

void printMenu();

void start(UI *user_interface);

service* get_service(UI *user_interface);

void deallocate_user_interface(UI *user_interface);

#endif //UNTITLED1_UI_H