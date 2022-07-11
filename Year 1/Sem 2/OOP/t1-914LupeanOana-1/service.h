//
// Created by Oana Lupean on 07.04.2022.
//

#ifndef T1_914LUPEANOANA_1_SERVICE_H
#define T1_914LUPEANOANA_1_SERVICE_H
#include "repository.h"

class Service {
private:
    Repository repo;
public:
    Service(Repository &r);

    Repository getRepo() const;

    // adds a school with the given data to the school repository
    void addServ(const std::string &name, const std::string adress, const std::string date);

    // adds 5 entries to the repo
    void initializeRepo();
};
#endif //T1_914LUPEANOANA_1_SERVICE_H
