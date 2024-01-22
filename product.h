#ifndef PRODUCT_H
#define PRODUCT_H
#include "design.h"
#include <string>

using namespace std;
class Product
{
    public:
        Product() = delete;
        Product(Design& designFromProduct);
        virtual ~Product();
        void getMachinesPersonalNumbers(int num);
        int getDemandsQuant() { return theDemand->getPurchaseQuantity(); }
        void decreaseTheDemandsQuantity() { theDemand->decrementQuantity(); }
        int productIDFromDemand() {theDemand->getId();}


    protected:

    private:

        Demand* theDemand;
        string fullCode;
        string progressReport;

};

#endif // PRODUCT_H
