//
// Created by Oana Lupean on 05.05.2022.
//

#include "Engine.h"

Engine::Engine() {

}

Engine::Engine(const std::string &fuel, const double& base_price) {
    this->fuel = fuel;
    this->base_price = base_price;
}

Engine::~Engine() {

}

double Engine::get_price() {
    return this->base_price;
}