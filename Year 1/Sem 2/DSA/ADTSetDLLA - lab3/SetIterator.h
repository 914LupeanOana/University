//
// Created by Oana Lupean on 09.05.2022.
//

#ifndef ADTSETDLLA_SETITERATOR_H
#define ADTSETDLLA_SETITERATOR_H

#include "Set.h"

class SetIterator
{
    //DO NOT CHANGE THIS PART
    friend class Set;
private:
    //DO NOT CHANGE THIS PART
    const Set& set;
    SetIterator(const Set& s);

    int current;

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};


#endif //ADTSETDLLA_SETITERATOR_H
