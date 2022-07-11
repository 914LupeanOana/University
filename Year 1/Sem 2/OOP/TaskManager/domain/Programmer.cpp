//
// Created by Oana Lupean on 12.06.2022.
//

#include "Programmer.h"

Programmer::Programmer(const string &name, const string& id) : name(name),id(id) {}


const string &Programmer::getName() const {
    return name;
}

const string& Programmer::getID() const {

    return id;
}


ostream &operator<<(ostream &os, const Programmer &programmer) {
    os << programmer.name << "," << programmer.id;
    return os;
}

istream &operator>>(istream &is, Programmer &programmer) {
    getline(is, programmer.name, ',');
    //string tmp;
    getline(is, programmer.id, '\n');
    //programmer.id = atoi(tmp.c_str());

    return is;
}
