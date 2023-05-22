//
// Created by Admin on 16.05.2023.
//

#ifndef PHYSICENGINE_VIEW_H
#define PHYSICENGINE_VIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "Object.h"
#include "vector"
#include "iostream"
#include "typeinfo"

class View {
    std::vector<Object*>& o;
public:
    View(std::vector<Object*>&);
    void present(sf::RenderWindow&) const;
    void drawObjects(sf::RenderWindow&) const;
};


#endif //PHYSICENGINE_VIEW_H
