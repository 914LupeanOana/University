//
// Created by Oana Lupean on 14.06.2022.
//


#include "CodeRepository.h"
#include <fstream>
#include <algorithm>

CodeRepository::CodeRepository() {
    readDrivers();
    readRoads();
}

const vector<Driver> &CodeRepository::getDrivers() const {
    return drivers;
}

const vector<Road> &CodeRepository::getRoads() const {
    return roads;
}

void CodeRepository::readDrivers() {
    string filename = "drivers.txt";
    ifstream f(filename);

    if (!f.is_open()) {
        fprintf(stderr, "Could not read from %s\n", filename.c_str());
        return;
    }

    Driver d;
    while (f >> d) { drivers.push_back(d); }

}

void CodeRepository::readRoads()  {
    string filename = "roads.txt"; // NOTE: add a blank line at the end, due to the Roads operator>>
    ifstream f(filename);

    if (!f.is_open()) {
        fprintf(stderr, "Could not read from %s\n", filename.c_str());
        return;
    }

    Road r;
    while (f >> r) { roads.push_back(r); }
}

void CodeRepository::addRoad(const string &description,int latit, int longit, Driver &driver) noexcept(false)  {
    if (description.empty()) throw std::runtime_error("Description must not be empty");
    if(abs(driver.getLatit() + driver.getLongit() - latit - longit)>20) throw std::runtime_error("Too far");


    roads.emplace_back(description, driver.getName(), latit, longit, "");
    notify();
}


Road CodeRepository::findSortedRoadByIndex(int index) const noexcept(false) {
    if (not isIndexValid(index))
        throw std::runtime_error("Invalid task selected");

    return getRoads()[index];
}


void CodeRepository::validateRoad(const string &description,Driver &driver) noexcept(false)  {
    // can throw, but, theoretically, it shouldn't since the original source of the name is the source files vector
    auto& road = findRoadByDescription(description);

    road.validate(driver.getName());


    notify();
}

void CodeRepository::updateDriverN(Driver &driver) noexcept(false) {
    driver.n();
    notify();
}

void CodeRepository::updateDriverS (Driver &driver) noexcept(false) {
    driver.s();
    notify();
}

void CodeRepository::updateDriverW(Driver &driver) noexcept(false) {
    driver.w();
    notify();
}

void CodeRepository::updateDriverE(Driver &driver) noexcept(false) {
    driver.e();
    notify();
}

Road &CodeRepository::findRoadByDescription(const string& description) noexcept(false) {
    for (auto &road: roads)
        if (road.getDescription() == description)
            return road;

    throw std::runtime_error("Invalid road selected");
}
