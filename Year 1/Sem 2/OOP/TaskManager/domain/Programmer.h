//
// Created by Oana Lupean on 12.06.2022.
//

#ifndef TASKMANAGER_PROGRAMMER_H
#define TASKMANAGER_PROGRAMMER_H

#include <iostream>

using namespace std;

class Programmer {
private:
    string name;
    string id;

public:
    Programmer(const string &name, const string& id);
    Programmer() = default;

    const string &getName() const;
    const string &getID() const;


    friend ostream &operator<<(ostream &os, const Programmer &programmer);
    friend istream &operator>>(istream &is, Programmer &programmer);


};

#endif //TASKMANAGER_PROGRAMMER_H
