#pragma once

#include "IItem.h"

class CheeseItem : public IItem {
   public:
    CheeseItem(const std::string& name, int days_remaining, int quality)
        : IItem(name, days_remaining, quality) {}
    virtual ~CheeseItem() = default;

    void update() override {
        const int quality_increment = (getDaysRemaining() <= 0) ? 2 : 1;

        incrementQualityBy(quality_increment);
        decrementDaysRemaining();
    }
};
