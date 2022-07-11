//
// Created by Oana Lupean on 05.05.2022.
//

#include "ElectricEngine.h"

ElectricEngine::ElectricEngine() {

}

ElectricEngine::ElectricEngine(const std::string& fuel, const double& base_price, const int &autonomy)
        :Engine(fuel, base_price), autonomy(autonomy)
{

}

ElectricEngine::~ElectricEngine() {

}


std::string ElectricEngine::to_string() {
    return "Electric engine with fuel " + this->fuel + ", base price " + std::to_string(this->base_price) + " and autonomy " + std::to_string(autonomy) + '\n';
}

double ElectricEngine::get_price() {
    return this->base_price + 0.01*100*this->autonomy;
}