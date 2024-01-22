#ifndef DEMAND_H
#define DEMAND_H

using namespace std;


class Demand
{
    public:
        Demand();
        Demand(int demandID, double price, int AmountOfMoney);
        virtual ~Demand();

        int getId() { return id; }
        void setId(int val) { val = id; }
        int getStatus() { return status; }
        void setStatus(int val) { val = status; }
        int getPricePoint() { return price_point; }
        void setPricePoint(int val) { val = price_point; }
        int getDesignValidationStatus() { return status; }
        void setDesignValidationStatus(bool val) { val = status; }
        int getPurchaseQuantity() { return purchaseQuantity; }
        void decrementQuantity() { purchaseQuantity--; }
        void display();


    protected:

        int id;
        bool status;
        int purchaseQuantity;
        int price_point;

    private:



};

#endif // DEMAND_H