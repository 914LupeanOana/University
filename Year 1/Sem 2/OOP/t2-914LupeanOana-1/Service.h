//
// Created by Oana Lupean on 05.05.2022.
//

#ifndef T2_914LUPEANOANA_1_SERVICE_H
#define T2_914LUPEANOANA_1_SERVICE_H

#include <vector>
#include "Engine.h"

class Service {
private:
    std::vector<Engine*> build;
public:
    Service();
    ~Service();
    void add_a_car(Engine* a);
    std::vector<Engine*> get_all_cars();

};

#endif //T2_914LUPEANOANA_1_SERVICE_H
