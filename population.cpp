#include "population.h"
#include "design.h"
#include "demand.h"
#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <list>
#include <cstdlib>

using namespace std;
Population::Population()
{
    //ctor
    incomeLevel = 4000;
}

Population::~Population()
{
    //dtor
}

void Population::randomDemandCreator(default_random_engine *gptr)
{
    uniform_real_distribution<double> randomDemands(1.0, 500.0);
    double cost = randomDemands(*gptr);
    static int demandID = 0;
    int numberOfConsumers = incomeLevel/cost;
    Demand newDemand(demandID, cost, numberOfConsumers);
    collectionOfDemands.push_back(newDemand);
    demandID++;
}

Demand Population::getDemand(int index)
{
    ditr = collectionOfDemands.begin();
    advance(ditr, index);
    if(!(ditr->getDesignValidationStatus()))
    {
        return *ditr;
    }
}

void Population::changePurchaseQuantity(double purchaseQuantity)
{
    for(Demand duhman : collectionOfDemands)
    {
        purchaseQuantity = incomeLevel / duhman.getPricePoint();
    }
}

void Population::displayMyDemands()
{
    for(Demand demandToPrint : collectionOfDemands)
    {
        demandToPrint.display();
    }

}
