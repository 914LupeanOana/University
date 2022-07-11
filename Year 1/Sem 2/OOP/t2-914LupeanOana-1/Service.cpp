//
// Created by Oana Lupean on 05.05.2022.
//

#include "Service.h"
#include <iostream>
#include <fstream>


Service::Service() {

}

Service::~Service() {
    for(auto &i : this->build)
        delete i;
}

void Service::add_a_car(Engine *a) {
    this->build.push_back(a);
}

std::vector<Engine *> Service::get_all_cars() {
    return this->build;
}