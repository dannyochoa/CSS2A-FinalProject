//*****************************************************************
//Author: Daniel Ochoa
//last modified: 5-10-17
//description: this class is made to format the upgrades that will
//change the velocity of the car. the main purpose of this class is
//to have the cost of the upgrade and the effect of the upgrade together
//*********************************************************************
#ifndef UPGRADE_H
#define UPGRADE_H
using namespace std;

class Upgrade
{
    public:
        Upgrade();
        Upgrade(double effect, int cost);
        void setEffect(double effect);
        void setCost(double cost);
        double getEffect()const{return effect;}
        int getCost()const{return cost;}
    private:
        double effect;
        int cost;
};

#endif // UPGRADE_H
