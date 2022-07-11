//
// Created by Oana Lupean on 07.04.2022.
//

#ifndef T1_914LUPEANOANA_1_UI_H
#define T1_914LUPEANOANA_1_UI_H
#include "service.h"

class Console
{
private:
    Service serv;

public:
    Console(Service& s);

    void run();

private:
    static void printMenu();

    void addUI();
    void displayAllSchools();

};
#endif //T1_914LUPEANOANA_1_UI_H
