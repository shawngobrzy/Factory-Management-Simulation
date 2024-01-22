#ifndef POPULATION_H
#define POPULATION_H
#include "design.h"
#include "demand.h"
#include <list>

using namespace std;


class Population
{
    public:
        Population();
        virtual ~Population();

        void randomDemandCreator(default_random_engine *gptr);
        int sendRandomDemandToRandD();
        Demand getDemand(int index);
        void changePurchaseQuantity(double purchaseQuantity);
        void displayMyDemands();
        int getIncomeLevel() { return incomeLevel; }
        void setIncomeLevel(int val) { val = incomeLevel; }
        list<Demand>& giveRandDTheDemands() { return collectionOfDemands; }

    protected:

    private:

         list<Demand>collectionOfDemands;
         list<Demand>::iterator ditr;
         int incomeLevel;

};

#endif // POPULATION_H
