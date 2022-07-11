//
// Created by Oana Lupean on 14.06.2022.
//

#ifndef E914_914LUPEANOANA_1_CODEREPOSITORY_H
#define E914_914LUPEANOANA_1_CODEREPOSITORY_H



#include <iostream>
#include <vector>
#include "../domain/driver.h"
#include "../domain/road.h"
#include "../domain/observer.h"


using namespace std;

class CodeRepository: public Subject {
private:
    vector<Driver> drivers;
    vector<Road> roads;
public:
    CodeRepository();

    const vector<Driver> &getDrivers() const;
    const vector<Road> &getRoads() const;
    bool isIndexValid(int index) const { return index >= 0 and index < roads.size(); }
    Road findSortedRoadByIndex(int index) const noexcept(false);
    void validateRoad(const string& description, Driver& driver) noexcept(false);
    void updateDriverN(Driver& driver) noexcept(false);
    void updateDriverS(Driver& driver) noexcept(false);
    void updateDriverW(Driver& driver) noexcept(false);
    void updateDriverE(Driver& driver) noexcept(false);

    void addRoad(const string& description,int latit, int longit, Driver& driver) noexcept(false);


private:
    void readDrivers();
    void readRoads();

    Road& findRoadByDescription(const string& description) noexcept(false);
};




#endif //E914_914LUPEANOANA_1_CODEREPOSITORY_H
