//
// Created by Oana Lupean on 09.05.2022.
//

#ifndef ADTSORTEDSETHASH_SORTEDSETITERATOR_H
#define ADTSORTEDSETHASH_SORTEDSETITERATOR_H

#include "SortedSet.h"

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
    friend class SortedSet;
private:
    SortedSet& multime;
    explicit SortedSetIterator(SortedSet& m);

    TElem current_element = NULL_TELEM;
    Node** current;
    // Node* current[8000];

public:
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;
    TComp remove();
};

#endif //ADTSORTEDSETHASH_SORTEDSETITERATOR_H
