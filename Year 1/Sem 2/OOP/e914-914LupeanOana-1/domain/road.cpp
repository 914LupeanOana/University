//
// Created by Oana Lupean on 14.06.2022.
//

#include "road.h"


Road::Road(const string &description, const string &reporter, int latit, int longit, const string& valid): description(description), reporter(reporter), latit(latit), longit(longit), valid(valid) {}

const string &Road::getDescription() const {
    return description;
}

const string &Road::getReporter() const {
    return reporter;
}

const string &Road::getValid() const  {
    return valid;
}

int Road::getLongit() const {
    return longit;
}

int Road::getLatit() const {
    return latit;
}


ostream &operator<<(ostream &os, const Road &road) {
    os << road.description << "," << road.reporter << "," << road.latit<< ","<< road.longit<<","<<road.valid;
    return os;
}

istream &operator>>(istream &is, Road &road) {
    getline(is, road.description, ',');
    getline(is, road.reporter, ',');
    string tmp;
    getline(is, tmp, ',');
    road.latit = atoi(tmp.c_str());
    getline(is, tmp, ',');
    road.longit = atoi(tmp.c_str());
    getline(is, road.valid, '\n');

    return is;
}

void Road::validate(const string &id) {

    valid = "yes";

}

