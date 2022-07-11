//
// Created by Oana Lupean on 05.05.2022.
//

#ifndef T2_914LUPEANOANA_1_ENGINE_H
#define T2_914LUPEANOANA_1_ENGINE_H

#include <string>

class Engine {
protected:
    std::string fuel;
    double base_price;
public:
    Engine();
    Engine(const std::string& fuel, const double& base_price);
    ~Engine();
    virtual std::string to_string() = 0;
    double get_price();

};

#endif //T2_914LUPEANOANA_1_ENGINE_H
