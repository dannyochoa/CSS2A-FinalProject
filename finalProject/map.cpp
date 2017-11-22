#include "map.h"
//Default constructor
Map::Map(){
    distance = 4800;
    launch = true;
    backPosition = -1;
    isStart = true;
    texture.loadFromFile("back1.jpg");
    sprite.setTexture(texture);

}
//Overloaded constructor for distance and launch
Map::Map(double distance, bool launch){
    this -> distance = distance;
    this -> launch = launch;

}
//Opens backgrounds for the game
void Map::activateLanchPad(RenderWindow& tempApp)
{

    const string arrowFile[5] = {"arrow1.png", "arrow2.png", "arrow3.png", "arrow4.png", "arrow5.png"};
    Texture t1, t2, t3, t4, t5 ;
    t1.loadFromFile(arrowFile[0]);
    t2.loadFromFile(arrowFile[1]);
    t3.loadFromFile(arrowFile[2]);
    t4.loadFromFile(arrowFile[3]);
    t5.loadFromFile(arrowFile[4]);
    Sprite sArrow1(t1), sArrow2(t2),sArrow3(t3), sArrow4(t4), sArrow5(t5);
    sArrow1.setPosition(-200,0);
    sArrow2.setPosition(-200,0);
    sArrow3.setPosition(-200,0);
    sArrow4.setPosition(-200,0);
    sArrow5.setPosition(-200,0);
    tempApp.draw(sArrow1);
    tempApp.display();
    tempApp.draw(sArrow2);
    tempApp.display();
    tempApp.draw(sArrow3);
    tempApp.display();
    tempApp.draw(sArrow4);
    tempApp.display();
    tempApp.draw(sArrow5);
    tempApp.display();

}
//Moves the background position depending on
//how fast the character is moving.
void Map::moveBackground(double velocity){
    backPosition -= velocity;
}
//Restarts the background every time the user
//is ready to launch
void Map::restart(){
    backPosition = -1;
    isStart = true;
    launch = true;
}

//Sets the background depending on what level
//you are at in the game
void Map::setBackground(double x)
{
    sprite.setPosition(x, 0);
}
