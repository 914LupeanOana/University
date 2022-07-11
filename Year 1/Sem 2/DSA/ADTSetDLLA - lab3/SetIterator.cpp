//
// Created by Oana Lupean on 09.05.2022.
//
#include "SetIterator.h"
#include "Set.h"
#include <exception>


SetIterator::SetIterator(const Set& m) : set(m)
{

    this->current = this->set.head;
}
// theta(1)

void SetIterator::first() {

    this->current = this->set.head;
}
// theta(1)

void SetIterator::next() {

    if (this->current == -1)
        throw std::exception();
    this->current = this->set.nodes[this->current].next;
}
// theta(1)

TElem SetIterator::getCurrent()
{

    if (this->current == -1)
        throw std::exception();

    return this->set.nodes[this->current].info;
}
// theta(1)

bool SetIterator::valid() const {

    if (this->current == -1)
        return false;
    else
        return true;
}
// theta(1)

