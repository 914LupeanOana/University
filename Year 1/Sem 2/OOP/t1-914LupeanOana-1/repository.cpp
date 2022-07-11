//
// Created by Oana Lupean on 07.04.2022.
//
#include "repository.h"
#include "exception.h"

void Repository::addSchool(const School& s)
 ///if the school already exists, there will be nothing added
 ///otherwise, it adds the school
 ///input - s school

{
    bool duplicate = false;
    DynamicVector<School> schools = getSchools();
    for (int i = 0; i < schools.getSize(); i++)
        if (schools[i] == s)
            duplicate = true;

    if (duplicate)
        throw RepoException("A school with the same name and address already exists!\n");

    this->schools.addElem(s);
}


DynamicVector<School> Repository::getSchools() const
{
    return this->schools;
}
