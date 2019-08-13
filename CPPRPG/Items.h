pragma once

#include "Header.h"

class Item
{


        public:
          Item(const std::string& name, int id, std::string& description)
           : name(name), itemId(id), desc(description) { };
          const string& getName(void) const { return this->name; }
          int getId(void) const { return this->itemId; }
          const string& getDesc(void) const { return this->description; }
        private:
          string name;
          int itemId;
          string description;

}
