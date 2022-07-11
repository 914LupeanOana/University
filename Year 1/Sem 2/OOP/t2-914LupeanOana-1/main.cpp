//
// Created by Oana Lupean on 05.05.2022.
//
#include <iostream>
#include "UI.h"
#include "Service.h"

int main(){
    Service serv;
    UI ui(serv);
    ui.run_command();
    return 0;
}
