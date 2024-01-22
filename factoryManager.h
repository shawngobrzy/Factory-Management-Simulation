#ifndef FACTORYMANAGER_H
#define FACTORYMANAGER_H
#include "design.h"
#include "product.h"
#include "machine.h"

#include <list>

using namespace std;


class FactoryManager
{
    public:
        FactoryManager();
        virtual ~FactoryManager();
        void sortMyMachinesBub();
        void putProductsInMachines();
        void recieveCollectionOfDesigns(list<Design>& myDesignsFromRandD);
        void assembleProducts();
        void setUpAssemblyLine();
        void displayMyMachines();
        void displayListFromRandD();
        void moveAlongTheLine();
        void optimizeTheEfficiencyOfMachines();

    protected:

    private:
        list<Design*>validDesigns;
        Machine lineOfMachines[24];
        //pair<double, int> [numberOfTotalProducts+1][numberOfTotalMachines+1];
        //int numberOfTotalProducts;
        int numberOfTotalMachines;



        struct comparator
        {
            bool operator() (Design* currentDesign, Design* nextDesign)
            {
                return((*currentDesign)<(*nextDesign));
            }
        };
};

#endif // FACTORYMANAGER_H
