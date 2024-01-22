#ifndef RANDD_H
#define RANDD_H
#include "design.h"
#include "demand.h"
#include <list>
#include <random>
using namespace std;


class RandD
{
    public:
        RandD();
        virtual ~RandD();

        //void designCreator(Demand& thisDemand, default_random_engine * gptr);
        void designCreator(list<Demand>& d, default_random_engine * gptr);
        void setDesign();
        list<Design>& sendDesignToFM() { return collectionOfValidDesgins; }
        void deleteInvalidDesigns();
        void checkPopulationForDecreaseInPurchaseQuantities();
        void displayMyDesigns();


    protected:

    private:

        list<Design>collectionOfValidDesgins;
        list<Design>collectionOfInValidDesgins;



};

#endif // RANDD_H