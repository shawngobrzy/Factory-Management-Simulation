#include "factoryManager.h"
#include "design.h"
#include "product.h"
#include "machine.h"
#include <iostream>

using namespace std;


FactoryManager::FactoryManager()
{
    //ctor
    numberOfTotalMachines = 24;
}

FactoryManager::~FactoryManager()
{
    //dtor
}

void FactoryManager::sortMyMachinesBub()
{
    validDesigns.sort(comparator());
}

void FactoryManager::putProductsInMachines()
{
    for(int i = 0; i < numberOfTotalMachines; i++)
    {

    }
}

void FactoryManager::recieveCollectionOfDesigns(list<Design>& myDesignsFromRandD)
{
    for(Design& justADesign : myDesignsFromRandD)
    {
        validDesigns.push_back(&justADesign);
    }

    validDesigns.sort();
    validDesigns.unique();

}

void FactoryManager::displayListFromRandD()
{
     for(Design* designToPrint : validDesigns)
    {
        designToPrint->displayDesigns();
    }
}

void FactoryManager::assembleProducts()
{

    int index = 0;

    for(Design* duh : validDesigns)
    {
        if(index+duh->getNumberOfMachines() > 23)
        {
            break;
        }

        for(int i = index; i < index+duh->getNumberOfMachines(); i++)
        {
            if(lineOfMachines[i].firstOrNah())
            {
                lineOfMachines[i].makeProduct(*duh);
            }
            else
            {
                lineOfMachines[i].getProductFromTheLastMachine(lineOfMachines[i-1].sendProductToNextMachine());
            }

            lineOfMachines[i].stampProgress();


            if(lineOfMachines[i].lastOrNah())
            {
                lineOfMachines[i].sendProductToPop();
            }
        }

        index += duh->getNumberOfMachines();
    }
}

void FactoryManager::setUpAssemblyLine()
{
    int place = 0;

    for(Design* d : validDesigns)
    {
        if(place+d->getNumberOfMachines() > 24)
        {
            cout << "you made a boo boo" << endl;
            cout << "no more machines butthead" << endl;
            break;
        }

        lineOfMachines[place].setFirst(true);
        lineOfMachines[place+d->getNumberOfMachines()-1].setLast(true);
        for(int i = 0; i < d->getNumberOfMachines(); i++)
        {
            lineOfMachines[place+i].setMachineID(d->getNumbersFromMachines(i));
        }

        place+=d->getNumberOfMachines();
    }
}

void FactoryManager::moveAlongTheLine()
{
    for(int i = 0; i < numberOfTotalMachines; i++)
    {
        lineOfMachines[i].moveProductAlongTheLine();
    }

}

void FactoryManager::displayMyMachines()
{
    int countCheck = 0;

    for(int i = 0; i < numberOfTotalMachines; i++)
    {
        cout << countCheck << endl;
        lineOfMachines[i].displayMachine(i);
        cout << "machine slot: " << i << " " << endl << endl;
        countCheck++;
    }
}