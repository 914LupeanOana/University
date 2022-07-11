#pragma once
#include <vector>
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
class ListIterator;
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);
typedef bool (*Condition)(TComp);
#define NULL_TCOMP (-11111)

class SortedIndexedList {
private:
    friend class ListIterator;
private:
    Relation R;

    struct node {
        TComp info;
        node* left;
        node* right;
        int nrLeft;
    };

    node* root;
    int sizeBST;


public:
    // constructor
    SortedIndexedList(Relation r);

    // returns the size of the list
    int size() const;

    //checks if the list is empty
    bool isEmpty() const;

    // returns an element from a position
    //throws exception if the position is not valid
    TComp getElement(int pos) const;

    // adds an element in the sortedList (to the corresponding position)
    void add(TComp e);

    // removes an element from a given position
    //returns the removed element
    //throws an exception if the position is not valid
    TComp remove(int pos);

    // searches for an element and returns the first position where the element appears or -1 if the element is not in the list
    int search(TComp e) const;

    //returns the get_successor of a given element
    TComp get_successor(TComp e);

    //modifies the position of the elements after the deletion of a node
    // Complexity: WC=O(n) when we have a degenerate tree and we need to get to the leaf - we need to parse through all of its other nodes as well
    //             BC=O(1) when the tree has a size of 1 (only contains the root)
    //			   AC=O(log n)
    void decrement(int i) const;

    // returns an iterator set to the first element of the list or invalid if the list is empty
    ListIterator iterator();

    //destructor
    ~SortedIndexedList();

    void filter(Condition cond);

};
