//
// Created by Admin on 16.05.2023.
//

#ifndef PHYSICENGINE_VIEW_H
#define PHYSICENGINE_VIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iomanip>
#include "Object.h"
#include "Controller.h"
#include "vector"
#include "iostream"
#include "typeinfo"

class View {
    std::vector<Object*>& o;
    Controller &c;
    sf::Font Oxproto, retrogastroll, openingHours;


    void drawObjects(sf::RenderWindow&) const;
    void drawPointer(sf::RenderWindow& ) const; //tmp name
    void Menu(sf::RenderWindow &) const;
    void menuPause(sf::RenderWindow &) const;
    void drawPause(sf::RenderWindow &) const;
    //text string, font, text color, text size, text outline color,
    //outline thickness, text position x, text position y
    //sf::Text createText(char &, sf::Font, sf::Color, int, sf::Color, int, float, float)const;

public:
    View(std::vector<Object*>&, Controller &);

    void present(sf::RenderWindow&) const;
};


#endif //PHYSICENGINE_VIEW_H
