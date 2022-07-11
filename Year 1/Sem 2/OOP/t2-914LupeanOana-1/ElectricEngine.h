//
// Created by Oana Lupean on 05.05.2022.
//

#ifndef T2_914LUPEANOANA_1_ELECTRICENGINE_H
#define T2_914LUPEANOANA_1_ELECTRICENGINE_H

#include <string>
#include "Engine.h"

class ElectricEngine : public Engine{
private:
    int autonomy;
public:
    ElectricEngine();
    ElectricEngine(const std::string& fuel, const double& base_price, const int& autonomy);
    ~ElectricEngine();
    std::string to_string() override;
    double get_price();
};



#endif //T2_914LUPEANOANA_1_ELECTRICENGINE_H
