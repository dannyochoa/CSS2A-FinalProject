#include "Upgrade.h"

Upgrade::Upgrade()
{
    effect = 10;
    cost = 20;
}

Upgrade::Upgrade(double effect, int cost)
{
    this->cost = cost;
    this->effect = effect;
}

void Upgrade::setEffect(double effect)
{
    this->effect = effect;
}

void Upgrade::setCost(double cost)
{
    this->cost = cost;
}
