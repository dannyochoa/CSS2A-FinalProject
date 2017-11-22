#include "Vehicle.h"

//Default constructor
Vehicle::Vehicle()
{
    velocity = 0;
    friction = .5;
    xcord = 0;
    ycord = 350;
    velocity_after_boost = 30;
    t1.loadFromFile("guy.png");
    s1.setTexture(t1);

}

//sets the x coordinate to 0 placing the sprite at the
//beginning of the screen and the velocity back to 0
void Vehicle::reset()
{
    xcord = 0;
    velocity = 0;
}

//sets the position of the sprite the x coordinate that is inputed
void Vehicle::moveVehicle(int xcord)
{
    s1.setPosition(xcord, this->ycord);
}

//decreases the vehicles velocity by the friction
void Vehicle::decreaseVelocity()
{
    velocity -= friction;
}
