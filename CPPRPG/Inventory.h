#pragma once

#include "Weapon.h"
#include <sstream>
#include <string>

class Inventory
{
private:
    Item **items;
    unsigned cap;
    unsigned nrOfItems;

    //Private Functions
    void initialize(const unsigned from = 0);
    void expand();

public:
    //Constructors / Destructors
    Inventory(unsigned cap = 10);
    Inventory(const Inventory& other);
    virtual ~Inventory();

    //Operators
    void operator = (const Inventory& other);
    Item& operator [] (const unsigned index);

    //Accessors
    const unsigned& size() const;
    const unsigned& capacity() const;
    Item& at(const unsigned index);

    //Modifiers

    //Functions
    void add(const Item& item);
    void remove(const unsigned index);
    std::string toString() const;


};