#include <iostream>
#include <list>
#include <random>
#include <string>
#include <time.h>
#include "demand.h"    
#include "design.h"
#include "product.h"
#include "population.h"
#include "RandD.h"
#include "machine.h"
#include "factoryManager.h"
using namespace std;

int main()
{

    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));

    Population thisPopulation;

    for(int i = 0; i < 6; i++)
    {
        thisPopulation.randomDemandCreator(gptr);
    }

    cout << "Creating demands in Population..." << endl << endl;

    thisPopulation.displayMyDemands();

    RandD researchAndDevelopemt;

    researchAndDevelopemt.designCreator(thisPopulation.giveRandDTheDemands(), gptr);

    researchAndDevelopemt.setDesign();

    cout << "-----------------------------------------------------" << endl << endl;

    cout << "Creating designs in RandD..." << endl << endl;

    researchAndDevelopemt.displayMyDesigns();

    FactoryManager fm;

    fm.recieveCollectionOfDesigns(researchAndDevelopemt.sendDesignToFM());

    cout << "-----------------------------------------------------" << endl << endl;

    cout << "Sending list from RandD to Factory manager..." << endl << endl;

    fm.displayListFromRandD();

    cout << "-----------------------------------------------------" << endl << endl;

    fm.sortMyMachinesBub();

    fm.setUpAssemblyLine();

    for(int i = 0; i < 10; i++)
    {
        fm.assembleProducts();

        fm.displayMyMachines();

        fm.moveAlongTheLine();
    }

    return 0;
}
