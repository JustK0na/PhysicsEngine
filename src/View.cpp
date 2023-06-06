//
// Created by Admin on 16.05.2023.
//

#include "View.h"



View::View(std::vector<Object*> &objects, Controller &controller):o(objects),c(controller)
{
    if(!Oxproto.loadFromFile("../graphics/fonts/0xproto/0xProto-Regular.ttf"))
        std::cout<<"\nFAILED TO LOAD 0xproto FONT";
    if(!retrogastroll.loadFromFile("../graphics/fonts/retrogastroll/Retro Gastroll.ttf"))
        std::cout<<"\nFAILED TO LOAD RetroGastroll FONT";
    if(!openingHours.loadFromFile("../graphics/fonts/openinghours/OpeningHoursMonoVF.ttf"))
        std::cout<<"\nFAILED TO LOAD OpeningHours FONT";
}
void View::Menu(sf::RenderWindow &win) const
{
    if(c.getLevel()!=MENU)
        return ;


    //  Program Name
    sf::Text sphereDrop("Sphere Drop", retrogastroll);
    sphereDrop.setFillColor(sf::Color(204, 198, 82));
    sphereDrop.setCharacterSize(55);
    sphereDrop.setPosition(SCREENWIDTH/2 - sphereDrop.getGlobalBounds().width/2,100);
    win.draw(sphereDrop);


    //  Mode1: Gravitational Field
    sf::Text gravitationalField("Gravitational Field", retrogastroll);
    if(c.getHighlight()==GRAVITATIONAL)
        gravitationalField.setFillColor(sf::Color::Red);
    else
        gravitationalField.setFillColor(sf::Color(235, 232, 176));

    gravitationalField.setCharacterSize(40);
    gravitationalField.setPosition(SCREENWIDTH/2 - gravitationalField.getGlobalBounds().width/2,300);
    win.draw(gravitationalField);


    //  Mode2: Planetary System

    sf::Text planetarySystem("Planetary System", retrogastroll);
    if(c.getHighlight()==PLANETARY)
        planetarySystem.setFillColor(sf::Color::Red);
    else
        planetarySystem.setFillColor(sf::Color(235, 232, 176));
    planetarySystem.setCharacterSize(40);
    planetarySystem.setPosition(SCREENWIDTH/2 - planetarySystem.getGlobalBounds().width/2,450);
   // std::cout<<"\nplanetary  x,y,height,width: "<<planetarySystem.getGlobalBounds().left<<", "<<planetarySystem.getGlobalBounds().top<<", "
   //         <<planetarySystem.getGlobalBounds().height<<", "<<planetarySystem.getGlobalBounds().width;
    win.draw(planetarySystem);



    //  Exit

    sf::Text exit("Exit", retrogastroll);
    if(c.getHighlight()==EXIT)
        exit.setFillColor(sf::Color::Red);
    else
        exit.setFillColor(sf::Color(235, 232, 176));
    exit.setCharacterSize(55);
    exit.setPosition(SCREENWIDTH/2 - exit.getGlobalBounds().width/2,720);
    win.draw(exit);



}
void View::drawObjects(sf::RenderWindow & win) const
{
    for(unsigned int i=0; i<o.size(); i++)
    {
       o[i]->draw(win);

    }
}
void View::present(sf::RenderWindow &win) const
{
    win.clear(sf::Color(0,0,0));

    drawObjects(win);
    Menu(win);
    win.display();
}

