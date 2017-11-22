//**************************************************
//Author of File: Daniel Ochoa
//Last modified: 5-10-17
//description: this is the driver file that connects all our
//classes together. It displays the game and implements the classes
//Summary: Our game was am upgrade game. repetition is needed to pass this
//game. The more times the user launches the more money they get which enables them
//to upgrade their vehicle to pass the game

//We used some code from https://www.sfml-dev.org/tutorials/2.4/start-cb.php
//the code that we got from there helped up get the graphics to work
//***************************************************************



#include <SFML/Graphics.hpp>
#include <cctype>
#include <iostream>
#include "map.h"
#include "Vehicle.h"
#include "Upgrade.h"
#include <string>
#include <sstream>
#include <cstdlib>

using namespace sf;
using namespace std;

int main()
{
    //these sprites are used in our program to show different menus
    //some of them upgrade the look of the car too
    Texture map2, map3, guy2, guy3, menu, menu2, menu3, congrats;
    map2.loadFromFile("back2.jpg");
    map3.loadFromFile("back3.jpg");
    guy2.loadFromFile("guy2.png");
    guy3.loadFromFile("guy3.png");
    menu.loadFromFile("menu.png");
    menu2.loadFromFile("menu2.png");
    menu3.loadFromFile("menu3.png");
    congrats.loadFromFile("congrats.png");
    Sprite smap2(map2), smap3(map3), sguy2(guy2), sguy3(guy3), smenu(menu), smenu2(menu2), smenu3(menu3),scongrats(congrats);

    //this is the only instance of the vehicle and map
    Vehicle v1;
    Map m1;

    //array of upgrade for each map. index 0 is or the first stage, index 1 is for the second stage and index 2 is for the final stage
    Upgrade stageUpgades[3] = {Upgrade(10,20), Upgrade(20,200),Upgrade(30,500)};

    //displays the current distance
    Font font;
    font.loadFromFile("arial.ttf");
    Text text("Distance : ", font);
    text.setCharacterSize(30);
    text.setStyle(Text::Bold);
    text.setColor(Color::White);

    //money needed to upgrade
    int money = 0;
    //currentStage is used as to get the correct upgrade at each stage
    int currentStage = 0;
    //choice is used for the user to input there choice
    char choice;
    //I use this as a switch so the user has to be forced to upgrade the look
    //of the car before passing the stage they are on.
    bool carUpGrade = false;

    //creates a window that will allow us to see what is going on
    RenderWindow app(VideoMode(1130, 554), "Vehicle Launch");
    app.setFramerateLimit(60);

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }
        if(v1.getVelocity() > 0)
        {
            m1.moveBackground(v1.getVelocity());
        }

        //draws the map
        app.draw(m1.getSprite());

        //the user is only allowed to use the right arrow key before the launch pad
        if (Keyboard::isKeyPressed(Keyboard::Right) && m1.getStart())
        {
            //this moves the vehicle when the user presses the right arrow key
            v1.moveX(2);
        }
        //when the vehicle x coordinate gets to 250 the launch pad gets activated
        if(v1.getX() == 250)
        {
            //sets the velocity of the vehicle
            v1.setVelocity(v1.getVelocityAfterBoost());
            m1.setStart(false);
        }
        //moves the background
        m1.setBackground(m1.getBackPosition());

        //moves the vehicle
        v1.moveVehicle(v1.getX());

        //draws the vehicle
        app.draw(v1.getSprite());

        //this is a little animation of the launch pad activating
        if(!m1.getStart() && v1.getX() == 250)
        {
            m1.activateLanchPad(app);
            v1.moveX(1);
        }

        //velocity decreases
        if (v1.getVelocity() >= 0)
            v1.decreaseVelocity();
        //this is were the user does
        if(v1.getVelocity() < 0 && v1.getX() > 250)
        {
            //calculates the money the player got for their run.
            money += (-1 * m1.getBackPosition()/ 100);
            cout << "Enter any letter to continue: ";
            cin >> choice;
            choice = '.';
            do
            {
                cout << "\n***************************\n";
                cout << "R - restart   U - upgrade\n";
                cout << "Balance: " << money << endl;
                //displays the correct upgrade menu
                //****************************************************************************
                if(!carUpGrade)
                {
                    cout << "next upgrade costs " << stageUpgades[currentStage].getCost() << endl;
                    app.draw(smenu);
                }
                if(carUpGrade && currentStage == 1)
                {
                    cout << "next upgrade costs 150\n";
                    app.draw(smenu2);
                }

                if(carUpGrade && currentStage == 2)
                {
                    cout << "next upgrade costs 300\n";
                    app.draw(smenu3);
                }
                //***************************************************************************
                //displays the correct menu
                app.display();
                //user enters there option
                cin >> choice;
                choice = tolower(choice);
                cout << "\n***************************\n";

                //resets the car back to the starting line
                if(choice == 'r')
                {
                    v1.reset();
                    m1.restart();
                }
                //upgrade the car's velocity
                if(!carUpGrade)
                {
                    //if the user has enough money to upgrade
                    if(choice == 'u' && money >= stageUpgades[currentStage].getCost())
                    {
                        v1.setVelocityAfterBoost(stageUpgades[currentStage].getEffect());
                        money -= stageUpgades[currentStage].getCost();
                        choice ='.';
                    }
                    //if the user does not have enough money to upgrade
                    if(choice == 'u' && money < stageUpgades[currentStage].getCost())
                        cout << "Not enough money to get this upgrade\n";
                }
                //upgrade the car's look
                if(carUpGrade)
                {
                    //this is the visual upgrade for stage two
                    if(choice == 'u' && money >= 150 && currentStage == 1)
                    {
                        v1.setSprite(sguy2);
                        money -= 150;
                        cout << "Balance: " << money << endl;
                        currentStage = 1;
                        carUpGrade = false;
                    }

                    //this is the visual upgrade for stage 3
                    if(choice == 'u' && money >= 300 && currentStage == 2)
                    {
                        v1.setSprite(sguy3);
                        money -= 300;
                        cout << "Balance: " << money << endl;
                        currentStage = 2;
                        carUpGrade = false;
                    }
                }
            //the user can continue to upgrade until they press restart
            }while(choice != 'r');
            choice = 'a';
        }

        //moves the user from stage one to stage two
        if(m1.getBackPosition() < -m1.getDistance() && currentStage == 0)
        {
            cout << "Congratulation you passed this level\nEnter any letter to continue\n";
            cin >> choice;
            choice = '.';
            v1.setVelocity(0);
            m1.setDistance(10000);
            v1.setFriction(1);
            m1.setSprite(smap2);
            v1.reset();
            m1.restart();
            choice == 'r';
            currentStage ++;
            carUpGrade = true;
        }

        //moves the user from stage two to stage 3
        if(m1.getBackPosition() < -m1.getDistance() && currentStage == 1)
        {
            cout << "Congratulation you passed this level\nEnter any letter to continue\n";
            cin >> choice;
            choice = '.';
            v1.setVelocity(0);
            m1.setDistance(15300);
            v1.setFriction(1.5);
            m1.setSprite(smap3);
            v1.reset();
            m1.restart();
            choice == 'r';
            currentStage ++;
            carUpGrade = true;
        }

        //this runs when the user passes the last stage
        if(m1.getBackPosition() < -m1.getDistance() && currentStage == 2)
        {
            cout << "Congratulation you win\n";
            app.draw(scongrats);
            cin >> choice;
            v1.setVelocity(0);
        }

        //displays the distance
        app.draw(text);
        stringstream ss;
        string newString;
        ss << -1 * m1.getBackPosition() << endl;
        newString = ss.str();
        Text text(newString, font);
        text.setCharacterSize(30);
        text.setStyle(Text::Bold);
        text.setColor(Color::White);
        text.setPosition(150,0);
        app.draw(text);
        //displays everything
        app.display();
    }


    return 0;
}
