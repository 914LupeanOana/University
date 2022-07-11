//
// Created by Oana Lupean on 07.04.2022.
//

#ifndef T1_914LUPEANOANA_1_REPOSITORY_H
#define T1_914LUPEANOANA_1_REPOSITORY_H
#include "school.h"
#include "DynamicVector.h"

class Repository
{
private:
    DynamicVector<School> schools;

public:
    // default constructor
    Repository() {}

    /*
        Adds a school to the repository.
        Input: s - school.
        Output: the school is added to the repository.
    */
    void addSchool(const School& s);

    DynamicVector<School> getSchools() const;
};
#endif //T1_914LUPEANOANA_1_REPOSITORY_H
