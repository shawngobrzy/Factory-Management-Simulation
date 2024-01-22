#include "machine.h"
#include "design.h"
#include "product.h"
#include "factoryManager.h"
#include <iostream>
using namespace std;

Machine::Machine()
{
    //ctor
    product1 = nullptr;
    product2 = nullptr;
    productID = 0;
    machineId = 0;
    first = false;
    last = false;

}

Machine::~Machine()
{
    //dtor
}


void Machine::stampProgress()
{
    if(product1 != nullptr)
    {
        product1->getMachinesPersonalNumbers(machineId);
    }
}


Product* Machine::sendProductToNextMachine()
{
    return product2;
}

void Machine::getProductFromTheLastMachine(Product* current)
{
    product1 = current;
}

 void Machine::moveProductAlongTheLine()
 {
     product2 = product1;
 }

void Machine::makeProduct(Design& d)
{
    cout << "Creating the product #" << d.getId() << endl;
    product1 = new Product(d);
}

void Machine::sendProductToPop()
{
    if(product2 != nullptr)
    {
        product2->decreaseTheDemandsQuantity();
    }
}

void Machine::displayMachine(int num)
{
    cout << "Machine slot #" << num << endl
    << "Machine id: " << machineId << endl;

    if(product1 == nullptr)
    {
        cout << "Product1 doesn't exist yet you idiot!" << endl;
    }
    else{

        cout << "Product1 #" << product1->productIDFromDemand() << endl;

    }




}
