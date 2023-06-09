﻿#ifndef _ARRAY_BAG
#define _ARRAY_BAG
#include <iostream>
#include "BagInterface.h"
using namespace std;


template <class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
    ItemType items[DEFAULT_CAPACITY]; // Array of bag items
    int itemCount; // Current count of bag items
    int maxItems; // Max capacity of the bag

    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain
    // the target.
    int getIndexOf(const ItemType& target);

public:
    ArrayBag();
    int getCurrentSize() const override;
    bool isEmpty() const override;
    bool add(const ItemType& newEntry) override;
    bool remove(const ItemType& anEntry) override;
    void clear() override;
    bool contains(const ItemType& anEntry) override;
    int getFrequencyOf(const ItemType& anEntry) override;
    vector<ItemType> toVector() const override;
    void display() const override;
    ItemType getElement(int index) const override;
}; // end ArrayBag

#endif
