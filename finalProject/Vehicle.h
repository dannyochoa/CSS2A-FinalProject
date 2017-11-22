//*****************************************************************
//Author: Emmanuel
//last modified: 5-10-17
//description: This is the header file for the vehicle class.
//It holds the different variables for each of our vehicles
//,allowing the vehicle to appear as though its moving.
//*********************************************************************
#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Vehicle
{
    public:
        Vehicle();

        //Setters
        void setVelocity(double velocity) {this->velocity = velocity;}
        void setFriction(double friction) {this->friction = friction;}
        void setX(double xcord) {this->xcord = xcord;}
        void setY(double ycord) {this->ycord = ycord;}
        void setVelocityAfterBoost(double velocity_after_boost) {this->velocity_after_boost += velocity_after_boost;}
        void setSprite(Sprite s1) {this->s1 = s1;}

        //Getters
        double getVelocity() const{return velocity;}
        double getFriction() const{return friction;}
        int getX() const{return xcord;}
        int getY() const{return ycord;}
        double getVelocityAfterBoost() const {return velocity_after_boost;}
        Sprite getSprite() const{return s1;}

        void reset();//resets the variables at the beginning of each stage
        void moveVehicle(int xcord);
        void moveX(int xcord) {this->xcord += xcord;}
        void decreaseVelocity();//"slows down" the sprite

    private:
        double velocity;
        double velocity_after_boost;
        int xcord;
        int ycord;
        Texture t1;
        Sprite s1;
        double friction;
};


#endif // VEHICLE_H_INCLUDED
