#ifndef DESIGN_H
#define DESIGN_H
#include "demand.h"
#include <random>
using namespace std;

class Design:public Demand
{
    public:
        Design() = delete;
        Design(Demand& demand1, int numBER, default_random_engine * gptr);
        Design(const Design& copyDesign);
        virtual ~Design();

        double getProfitMargin() { return profitMargin; }
        void setProfitMargin(int val) { val = profitMargin; }
        void profitPerMachine();
        int getNumberOfMachines() { return numberOfMachines; }
        void setNumberOfMachine(int val) { val = numberOfMachines; }
        int getNumbersFromMachines(int val) const;
        bool operator< (const Design &rhs) const;
        bool operator== (const Design &rhs) const;
        Demand* getCurrentDemand() { return this->demandPtr; }

        void displayDesigns();


    protected:

    private:
        double profitMargin;
        Demand* demandPtr;
        int profitNumber;
        double ppm;
        const int numberOfMachines;
        int* machines;
};

#endif // DESIGN_H
