#include "WhiteBear.h"
#include "NormalItem.h"

using namespace std;

int main() {
    WhiteBear app;

    app.addItem(new NormalItem("+7 Yellow Vest", 10, 20));

    cout << "HAHAHA!" << endl;
    app.updateQuality();
    app.printItems(cout);
}
