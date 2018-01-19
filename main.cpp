#include "Beverage.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Beverage *beverage = new Espresso(VENTI);
    cout << beverage->getDescription() << " size " << beverage->getSize() <<" $ " << beverage->cost() << endl;
    beverage = new Mocha(beverage);
    cout << beverage->getDescription() << " size " << beverage->getSize() <<" $ " << beverage->cost() << endl;
    beverage = new Mocha(beverage);
    cout << beverage->getDescription() << " size " << beverage->getSize() <<" $ " << beverage->cost() << endl;
    delete(beverage);

    Beverage *beverage2 = new HouseBlend(GRANDE);
    cout << beverage2->getDescription() << " size " << beverage2->getSize() <<" $ " << beverage2->cost() << endl;
    beverage2 = new Mocha(beverage2);
    cout << beverage2->getDescription() << " size " << beverage2->getSize() <<" $ " << beverage2->cost() << endl;
    beverage2 = new Soy(beverage2);
    cout << beverage2->getDescription() << " size " << beverage2->getSize() <<" $ " << beverage2->cost() << endl;
    delete(beverage2);

    return 0;
}
