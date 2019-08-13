pragma once

#include "Header.h"

class Item
{


        public:
          Item(const std::string& name, int id)
           : name(name), itemId(id) { }
          const string& getName(void) const { return this->name; }
          int getId(void) const { return this->itemId; }
        private:
          string name;
          int itemId;

}
