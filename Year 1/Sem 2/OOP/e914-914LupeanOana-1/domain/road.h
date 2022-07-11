//
// Created by Oana Lupean on 14.06.2022.
//

#ifndef E914_914LUPEANOANA_1_ROAD_H
#define E914_914LUPEANOANA_1_ROAD_H


#include <iostream>

using namespace std;

class Road {
private:
    string description;
    string reporter;
    int latit, longit;
    string valid;

public:
    Road(const string &description, const string &reporter, int latit, int longit, const string& valid);
    Road() = default;

    const string &getDescription() const;
    const string &getReporter() const;
    const string &getValid() const;
    int getLatit() const;
    int getLongit() const;


    bool isValidated() const { return valid == "yes"; }

    friend ostream &operator<<(ostream &os, const Road &road);
    friend istream &operator>>(istream &is, Road &road);

    void validate(const string &name);

};



#endif //E914_914LUPEANOANA_1_ROAD_H
