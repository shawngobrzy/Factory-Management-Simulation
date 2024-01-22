#include "demand.h"
#include <iostream>

using namespace std;

Demand::Demand()
{
    //ctor
    id = 0;
    price_point = 0;
    purchaseQuantity = 0;
}

Demand::Demand(int demandID, double price, int AmountOfMoney)
{
    id = demandID;
    price_point = price;
    purchaseQuantity = AmountOfMoney;
}

Demand::~Demand()
{
    //dtor
}

void Demand::display()
{
    cout << "Demand #" << id << endl
    << "Quantity:" << purchaseQuantity << endl
    << "Price point:" << price_point << endl << endl;
}
