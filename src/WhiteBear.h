#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "IItem.h"

class WhiteBear {
   public:
    void printItems(std::ostream&);
    void addItem(IItem* item);
    void updateQuality();

   private:
    std::vector<ItemPointer> items_;
};
