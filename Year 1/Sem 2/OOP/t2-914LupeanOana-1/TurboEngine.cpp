//
// Created by Oana Lupean on 05.05.2022.
//

#include "TurboEngine.h"

TurboEngine::TurboEngine() {

}

TurboEngine::TurboEngine(const std::string &fuel, const double &base_price)
        :Engine(fuel, base_price)
{

}

TurboEngine::~TurboEngine() {

}


std::string TurboEngine::to_string() {
    return "Turbo engine with fuel " + this->fuel + " and base price " + std::to_string(this->base_price) + '\n';
}


double TurboEngine::get_price() {
    if (this->fuel == "gasoline")
        return this->base_price + 0.01 * 100 * this->base_price;
    else
        return this->base_price + 0.01 * 150 * this->base_price;
}