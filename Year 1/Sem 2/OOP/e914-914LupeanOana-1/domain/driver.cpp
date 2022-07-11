//
// Created by Oana Lupean on 14.06.2022.
//

//
// Created by Oana Lupean on 12.06.2022.
//

#include "driver.h"

Driver::Driver(const string &name, const string &status, int latit, int longit, int score) {}


const string &Driver::getName() const {
    return name;
}

const string& Driver::getStatus() const {

    return status;
}

int Driver::getLatit() const {
    return latit;
}

int Driver::getLongit() const {
    return longit;
}

int Driver::getScore() const {
    return score;
}

ostream &operator<<(ostream &os, const Driver &driver) {
    os << driver.name << "," << driver.status << ","<< driver.latit << "," << driver.longit<<","<<driver.score;
    return os;
}

istream &operator>>(istream &is, Driver &driver) {
    getline(is, driver.name, ',');
    getline(is, driver.status, ',');
    string tmp;
    getline(is, tmp, ',');
    driver.latit = atoi(tmp.c_str());
    getline(is, tmp, ',');
    driver.longit = atoi(tmp.c_str());
    getline(is, tmp, '\n');
    driver.score = atoi(tmp.c_str());

    return is;
}

void Driver::n(){
    latit++;
}

void Driver::s(){
    latit--;
}

void Driver::w(){
    longit--;
}

void Driver::e(){
    longit++;
}