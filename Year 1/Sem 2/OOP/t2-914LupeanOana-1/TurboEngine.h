//
// Created by Oana Lupean on 05.05.2022.
//

#ifndef T2_914LUPEANOANA_1_TURBOENGINE_H
#define T2_914LUPEANOANA_1_TURBOENGINE_H

#include <string>
#include "Engine.h"

class TurboEngine : public Engine{

public:
    TurboEngine();
    TurboEngine(const std::string& fuel, const double& base_price);
    ~TurboEngine();
    std::string to_string() override;
    double get_price();
};


#endif //T2_914LUPEANOANA_1_TURBOENGINE_H
