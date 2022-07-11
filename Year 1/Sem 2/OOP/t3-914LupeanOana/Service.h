//
// Created by Oana Lupean on 26.05.2022.
//

#ifndef UNTITLED6_SERVICE_H
#define UNTITLED6_SERVICE_H

#include <vector>
#include <fstream>
#include "Domain.h"

using namespace std;

class Service {
private:
    vector<Domain> all;

protected:
    string path;

    void save(vector<Domain> all);

public:

    Service() = default;

    Service(const string &path);

    vector<Domain> load_content();

};


#endif //UNTITLED6_SERVICE_H
