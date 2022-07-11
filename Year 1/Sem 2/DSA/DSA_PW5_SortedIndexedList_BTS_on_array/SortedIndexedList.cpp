#include "ListIterator.h"
#include "SortedIndexedList.h"
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
    this->R = r;
    this->root = nullptr;
    this->sizeBST = 0;
}
//Theta(1)

void SortedIndexedList::add(TComp e) {
    node* newNode = new node;
    newNode->info = e;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->nrLeft = 0;
    if (root == nullptr)
        root = newNode;
    else
    {
        node* current = this->root;
        while (current)
        {
            if (this->R(e, current->info))
            {
                current->nrLeft++;
                if (current->left == nullptr)
                {

                    current->left = newNode;
                    current = nullptr;
                }
                else current = current->left;
            }
            else
            {
                //
                if (current->right == nullptr)
                {
                    current->right = newNode;
                    current = nullptr;
                }
                else current = current->right;
            }
        }
    }
    this->sizeBST++;
}
//BC: O(1)   WC: O(n)  -> AC: O(log(n))

int SortedIndexedList::size() const {
    if (root == nullptr) return 0;
    return this->sizeBST;
}
//T(1)

bool SortedIndexedList::isEmpty() const {
    if (this->sizeBST == 0) return true;
    return false;
}
//T(1)



TComp SortedIndexedList::getElement(int i) const {
    if (i < 0 || i >= this->sizeBST)
    {
        exception myex;
        throw(myex);
    }
    node* current = this->root;
    int position = 0;
    while (current != nullptr)
    {
        if (i == position + current->nrLeft)return current->info;
        if (i < position + current->nrLeft)
        {
            current = current->left;
        }
        else
        {
            position = position + current->nrLeft + 1;
            current = current->right;
        }
    }
}
//BC: O(1)   WC: O(n)  -> AC: O(log(n))

TComp SortedIndexedList::remove(int i) {
    if (i < 0 || i >= this->sizeBST)
    {
        exception myex;
        throw(myex);
    }
    node* prev = nullptr;
    node* current = this->root;
    int position = 0;
    if (this->sizeBST == 1 && i == position)
    {
        int deleted = current->info;
        delete[] current;
        this->sizeBST--;
        this->root = nullptr;
        return deleted;
    }
    while (current)
    {
        //searching for the node
        if (i == position + current->nrLeft) break;
        if (i < position + current->nrLeft)
        {
            prev = current;
            current = current->left;
        }
        else
        {
            prev = current;
            position = position + current->nrLeft + 1;
            current = current->right;
        }
    }
    int deleted = current->info;

    if (current->left == nullptr && current->right == nullptr)
    {
        decrement(i);
        if (prev == nullptr)
        {
            this->root == nullptr;
        }
        else
        {
            if (this->R(current->info, prev->info)) prev->left = nullptr;
            else prev->right = nullptr;
            delete[] current;
        }
        this->sizeBST--;
    }
    else
    {
        if (current->left == nullptr || current->right == nullptr)
        {
            decrement(i);

            node* descendant;
            if (current->left == nullptr)
                descendant = current->right;
            else
                descendant = current->left;

            if (prev == nullptr)
            {
                //root
                this->root = descendant;
            }
            else
            {
                //not root
                if (this->R(current->info, prev->info))
                {
                    //on left
                    prev->left = descendant;
                }
                else
                {
                    //on right
                    prev->right = descendant;
                }
                delete[] current;

            }
            this->sizeBST--;
        }
        else
        {
            TComp ssuccessor = this->get_successor(current->info);
            int index = this->search(ssuccessor);

            this->remove(index);

            current->info = ssuccessor;
        }
    }
    return deleted;
}
//BC: O(1)   WC: O(n)  -> AC: O(log(n))

void SortedIndexedList::decrement(int i) const
{
    if (i >= this->sizeBST || i < 0)
        throw(exception());

    node* current = this->root;
    int position = 0;
    while (current)
    {
        if (i == position + current->nrLeft)
            return;
        if (i < position + current->nrLeft)
        {
            //left
            current->nrLeft--;
            current = current->left;
        }
        else
        {
            //right
            position = position + current->nrLeft + 1;
            current = current->right;
        }
    }

}

TComp SortedIndexedList::get_successor(TComp e)
{
    node* current = this->root;
    while (current->info!=e)
    {

        if (this->R(e, current->info)) current = current->left;
        else current = current->right;

    }
    current = current->right;
    while (current->left)
        current = current->left;
    return current->info;
}

int SortedIndexedList::search(TComp e) const {
    node* current = this->root;
    int position = 0;
    while (current != nullptr)
    {
        //return position
        if (current->info == e)return position+current->nrLeft;
        if (this->R(e,current->info)) current = current->left;
        else
        {
            position = position+current->nrLeft+1;
            current = current->right;
        }
    }
    return -1;
}
//BC: O(1)   WC: O(n)  -> AC: O(log(n))

ListIterator SortedIndexedList::iterator(){
    return ListIterator(*this);
}
//T(1)

//destructor
SortedIndexedList::~SortedIndexedList() {
    while (!this->isEmpty())this->remove(0);

}
//T(1)

