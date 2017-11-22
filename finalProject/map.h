//*****************************************************************
//Author: Vanessa Nava
//Contributor: Daniel Ochoa
//last modified: 5-10-17
//description:
//*********************************************************************

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class Map{
private:
    double distance;
    Texture texture;
    Sprite sprite;
    double backPosition;
    bool launch;
    bool isStart;



public:
//Constructors
    Map();
    Map(double distance, bool launch);

    //Setters
    void setDistance(double distance){this -> distance = distance;}
    void setSprite(Sprite sprite){this -> sprite = sprite;}
    void setTexture(Texture texture){this -> texture = texture;}
    void setLaunch(bool launch){this -> launch = launch;}
    void setStart(bool isStart){this -> isStart = isStart;}
    void setBackground(double x);

    //Getters
    double getBackPosition() const {return backPosition;}
    double getDistance()const{return distance;}
    Sprite getSprite()const{return sprite;}
    Texture getTexture()const{return texture;}
    bool getLaunch()const{return launch;}
    bool getStart()const{return isStart;}


    //Functions
    void moveBackground(double velocity);
    void activateLanchPad(RenderWindow& tempApp);
    void restart();

};

#endif // MAP_H_INCLUDED
