//
// Created by Admin on 17.05.2023.
//

#ifndef PHYSICENGINE_CONTROLLER_H
#define PHYSICENGINE_CONTROLLER_H
#define FRAMERATE 60

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "iostream"
#include <math.h>

#include "vector"
#include "Object.h"

#define FRICTION 0.999

class Controller {
    std::vector<Object* >& o;
public:
    Controller(std::vector<Object* > &);
    void control(sf::RenderWindow &);  
    void addObject(sf::Event &);
    void update();

    int constrainEdges(Object *o);
    int checkCollision();
    void resolveCollision(Object*,Object*);

    void solver(Object*, float);
    std::vector<float> acceleration(Object *);




};


#endif //PHYSICENGINE_CONTROLLER_H
