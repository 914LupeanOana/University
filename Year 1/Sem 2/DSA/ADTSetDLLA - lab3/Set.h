//
// Created by Oana Lupean on 09.05.2022.
//

#ifndef ADTSETDLLA_SET_H
#define ADTSETDLLA_SET_H

//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111
typedef int TElem;
class SetIterator;

struct Node {
    TElem info;
    int next;
    int prev;
};

class Set {
    //DO NOT CHANGE THIS PART
    friend class SetIterator;

private:
    //TODO - Done
    struct Node* nodes;
    int capacity;
    int head;
    int tail;
    int first_empty;


public:
    //implicit constructor
    Set();

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(TElem e);

    //removes an element from the set
    //returns true if e was removed, false otherwise
    bool remove(TElem e);

    //checks whether an element belongs to the set or not
    bool search(TElem elem) const;

    //returns the number of elements;
    int size() const;

    //check whether the set is empty or not;
    bool isEmpty() const;

    //return an iterator for the set
    SetIterator iterator() const;

    // destructor
    ~Set();

    void resize();

    //keeps only the elements which appear in s as well
    void intersection(const Set& s);

};




#endif //ADTSETDLLA_SET_H
