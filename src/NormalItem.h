#pragma once

#include "IItem.h"

class NormalItem : public IItem {
   public:
    NormalItem(const std::string& name, int days_remaining, int quality)
        : IItem(name, days_remaining, quality) {}
    virtual ~NormalItem() = default;

    void update() override {
        const int quality_decrement = (getDaysRemaining() <= 0) ? 2 : 1;

        decreaseQualityBy(quality_decrement);
        decreaseDaysRemaining();
    };
};
