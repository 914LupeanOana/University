//
// Created by Oana Lupean on 14.06.2022.
//

#ifndef E914_914LUPEANOANA_1_DRIVER_H
#define E914_914LUPEANOANA_1_DRIVER_H

#include <iostream>

using namespace std;

class Driver {
private:
    string name, status;
    int latit, longit, score;

public:
    Driver(const string &name, const string& status, int latit, int longit, int score);
    Driver() = default;

    const string &getName() const;
    const string &getStatus() const;
    int getLatit() const;
    int getLongit() const;
    int getScore() const;

    void n();
    void w();
    void s();
    void e();

    friend ostream &operator<<(ostream &os, const Driver &driver);
    friend istream &operator>>(istream &is, Driver &driver);


};


#endif //E914_914LUPEANOANA_1_DRIVER_H
