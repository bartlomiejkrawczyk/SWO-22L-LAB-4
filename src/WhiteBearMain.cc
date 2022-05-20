#include "WhiteBear.h"
#include "NormalItem.h"

int main() {
    WhiteBear app;

    app.addItem(new NormalItem("+7 Yellow Vest", 10, 20));

    app.updateQuality();
    app.printItems(std::cout);
}
