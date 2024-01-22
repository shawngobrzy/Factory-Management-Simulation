#include "design.h"
#include "demand.h"
#include <iostream>

using namespace std;

Design::Design(Demand& demand1, int numBER, default_random_engine * gptr)
            :numberOfMachines(numBER)
{
    this->id = demand1.getId();
    this->status = demand1.getStatus();
    demandPtr = &demand1;

    this->machines = new int [numberOfMachines];
    int sum = 0;
    for(int i = 0; i < numberOfMachines; i++)
    {
        uniform_int_distribution<int> numberRandomizer(1,12);
        machines[i] = numberRandomizer(*gptr);
        sum += machines[i];

    }

    this->profitMargin = demandPtr->getPricePoint() - sum;

}

Design::Design(const Design& copyDesign)
    :numberOfMachines(copyDesign.numberOfMachines)
{
    this->id = copyDesign.id;
    this->machines = new int [numberOfMachines];
    for(int i=0; i<numberOfMachines; i++)
    {
        machines[i] = copyDesign.getNumbersFromMachines(i);
    }
    this->status = copyDesign.status;
    this->profitMargin = copyDesign.profitMargin;
    this->demandPtr = copyDesign.demandPtr;

}


Design::~Design()
{
    delete [] machines;
}

void Design::profitPerMachine()
{   ppm = profitNumber/numberOfMachines;
   /// return const(profitNumber / numberOfMachines);
}

bool Design::operator< (const Design &rhs) const
{

    if(this->ppm<rhs.ppm)
    {
        return true;
    }
else {return false;}
    //return this->profitPerMachine() < rhs->profitPerMachine();

}

bool Design::operator== (const Design &rhs) const
{
    return this->id == rhs.id;
}
int Design::getNumbersFromMachines(int val) const
{
    return machines[val];
}

void Design::displayDesigns()
{
    cout << "Design #" << id << endl
    << "Valid: " << status << endl
    << "Machine Order: " << "[ ";

    for(int i = 0; i < numberOfMachines; i++)
    {
        cout << machines[i] << " ";
    }

    cout << "]" << endl;

    cout << "Profit margin: " << profitMargin << endl << endl;

}