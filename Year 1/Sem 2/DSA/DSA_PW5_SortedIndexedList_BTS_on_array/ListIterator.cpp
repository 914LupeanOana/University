#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
    this->currentPosition = 0;
}
//T(1)

void ListIterator::first() {
    this->currentPosition = 0;
}
//T(1)

void ListIterator::next() {

    if (!this->valid())
    {
        exception myex;
        throw myex;
    }
    this->currentPosition++;
}
//T(1)

bool ListIterator::valid() const {
    if (this->currentPosition < list.size())return true;
    return false;
}
//T(1)

TComp ListIterator::getCurrent() const {
    if (!this->valid())
    {
        exception myex;
        throw myex;
    }
    return list.getElement(this->currentPosition);
}
//BC: O(1)   WC: O(n)  -> AC: O(log(n))

void ListIterator::jumpBackward(int k) {

    if( k <= 0 || !this->valid())
    {
        exception myex;
        throw myex;
    }
    int currentkey = this->getCurrent();
    //std::cout<<currentkey;
    int currentpos = 0;
    while(list.getElement(currentpos) != currentkey) {
        currentpos++;
    }
    int newpos = currentpos - k ;
    //std::cout<<newpos;
    if (newpos < 0){
        this->currentPosition = list.size() +1;
        return; }
    else
    {
        currentpos = 0;
        while (currentpos < newpos) {

            currentpos++;
        }
        return;
    }


}