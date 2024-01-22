#include "product.h"
#include "demand.h"
#include "design.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;

Product::Product(Design& designFromProduct)
{
    //ctor
   // progressReport

   theDemand = designFromProduct.getCurrentDemand();
    for(int i = 0; i < designFromProduct.getNumberOfMachines(); i++)
    {
        fullCode = fullCode + to_string(designFromProduct.getNumbersFromMachines(i));
    }
    progressReport = '\0';

}

Product::~Product()
{
    //dtor
}

void Product::getMachinesPersonalNumbers(int num)
{
    progressReport += to_string(num);
}
