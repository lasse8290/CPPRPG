pragma once

#include "Header.h"

class Item
{


        public:
          Item(const std::string& name, int id, std::string& description, int worth)
           : name(name), itemId(id), desc(description), itemWorth(worth) { };
          const string& getName(void) const { return this->name };
          int getId(void) const { return this->itemId };
          const string& getDesc(void) const { return this->desc };
          int getWorth(void) const { return this->itemWorth };
        private:
          string name;
          int itemId;
          string desc;
          int itemWorth;

}
