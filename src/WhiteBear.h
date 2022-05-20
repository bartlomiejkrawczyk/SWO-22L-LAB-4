#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "IItem.h"

class WhiteBear;

class WhiteBear {
   public:
    void printItems(std::ostream&);
    void addItem(IItem* item);
    void updateQuality();

   private:
    std::vector<ItemPointer> items_;
};

const std::string item1 = "Aged Cheese";
const std::string item2 = "Tickets to a concert";
const std::string item3 = "Legolas, Hand of Gollum";
