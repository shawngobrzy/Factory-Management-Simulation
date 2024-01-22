#include "RandD.h"
#include "design.h"
#include "demand.h"
#include <iostream>
#include <random>
#include <list>
using namespace std;

RandD::RandD()
{
    //ctor
}

RandD::~RandD()
{
    //dtor
}

void RandD::designCreator(list<Demand>& d, default_random_engine * gptr)
{
    int tempNum = 0;

    ///Mean = 5, STDev = 1

    for(Demand& theDemands : d)
    {
        normal_distribution<double> thedesign(5.0,1.0);

        tempNum = static_cast<int> (thedesign(*gptr));

        Design theCurrentDesigns(theDemands, tempNum, gptr);

        collectionOfInValidDesgins.push_back(theCurrentDesigns);
    }


}

void RandD::setDesign()
{
    for(Design& invalidDesigns : collectionOfInValidDesgins)
    {
        if(invalidDesigns.getProfitMargin() > 0)
        {
            collectionOfValidDesgins.push_back(invalidDesigns);
        }
    }

    for(Design& designsToBeProduced : collectionOfValidDesgins)
    {
        collectionOfInValidDesgins.remove(designsToBeProduced);
        designsToBeProduced.setStatus(true);
    }
}

void RandD::displayMyDesigns()
{
    for(Design designToPrint : collectionOfValidDesgins)
    {
        designToPrint.displayDesigns();
    }
}
