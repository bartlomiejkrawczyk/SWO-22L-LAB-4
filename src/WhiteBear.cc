#include "WhiteBear.h"

std::ostream& operator<<(std::ostream& s, const IItem& item) {
    s << item.getName() << ", " << item.getDaysRemaining() << ", " << item.getQuality();
    return s;
}

void WhiteBear::updateQuality() {
    for (auto& i : items_) i->update();
}

void WhiteBear::addItem(IItem* item) { items_.emplace_back(item); }

void WhiteBear::printItems() {
    for (auto const& i : items_) std::cout << *i << std::endl;
}
