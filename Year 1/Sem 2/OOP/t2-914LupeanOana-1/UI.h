//
// Created by Oana Lupean on 05.05.2022.
//

#ifndef T2_914LUPEANOANA_1_UI_H
#define T2_914LUPEANOANA_1_UI_H

#include "Service.h"

class UI {
private:
    Service service;
public:
    UI(Service service);
    UI();
    ~UI();
    void print_menu();
    void run_command();
    void add_a_new_car();
    void show_all_cars();
    void initial_list();

};


#endif //T2_914LUPEANOANA_1_UI_H
