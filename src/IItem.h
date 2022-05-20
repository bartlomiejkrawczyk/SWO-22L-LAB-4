#pragma once
#include <memory>
#include <string>

class IItem;
using ItemPointer = std::shared_ptr<IItem>;

class IItem {
   public:
    IItem(const std::string& name, int sell_in, int quality)
        : name_{name},
          sell_in_{sell_in},
          quality_{quality},
          max_quality_{50},
          min_quality_{0} {}

    virtual ~IItem() = default;

    int getQuality() const { return quality_; };
    int getDaysRemaining() const { return sell_in_; };
    const std::string& getName() const { return name_; };

    virtual void update() = 0;

   protected:
    void decrementSellIn() { sell_in_ -= 1; }

    void decrementQualityBy(const int quality_decrement) {
        quality_ = std::max(quality_ - quality_decrement, min_quality_);
    }

    void incrementQualityBy(const int quality_increment) {
        quality_ = std::min(quality_ + quality_increment, max_quality_);
    }

    void setToMinimumQuality() { quality_ = min_quality_; }

   private:
    std::string name_;
    int sell_in_;
    int quality_;
    const int max_quality_;
    const int min_quality_;
};
