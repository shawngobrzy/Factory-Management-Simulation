#ifndef MACHINE_H
#define MACHINE_H
#include "design.h"
#include "product.h"
#include <list>

using namespace std;


class Machine
{
    public:
        Machine();
        virtual ~Machine();
        void makeProduct(Design& d);
        int getMachineID() { return machineId; }
        void setMachineID(int val) { machineId = val; }
        Product* sendProductToNextMachine();
        void stampProgress();
        void getProductFromTheLastMachine(Product* current);
        bool firstOrNah() { return first; }
        void setFirst(bool val) { first = val; }
        bool lastOrNah() { return last; }
        void setLast(bool val) { last = val; }
        void sendProductToPop();
        void displayMachine(int num);
        void moveProductAlongTheLine();

    protected:

    private:

        int productID;
        bool first;
        bool last;
        Product* product1;
        Product* product2;
        Design* design;
        int machineId;

};

#endif // MACHINE_H