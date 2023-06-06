//
// Created by Admin on 17.05.2023.
//

#ifndef PHYSICENGINE_CONTROLLER_H
#define PHYSICENGINE_CONTROLLER_H

#define FRAMERATE 60
#define SCREENHEIGHT 900
#define SCREENWIDTH 1600


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "iostream"
#include <math.h>

#include "vector"
#include "Object.h"

#define FRICTION 0.999
enum LEVEL{
    MENU,
    GRAVITYFIELD,
    PLANETARYSYSTEM
};
enum STATE{
    RUNNING,
    PAUSE
};
enum HIGHLIGHT{
    GRAVITATIONAL,
    PLANETARY,
    EXIT,
    NONE
};
class Controller {
    std::vector<Object* >& o;
    LEVEL level;
    HIGHLIGHT highlight;
    STATE state;

    void addObject(sf::Event &, sf::Window &);
    void addForces(Object *);

    std::vector<float> calculateAcceleration(Object *   );

    void changePosition(Object *);

    void update();


    void changeLevel(sf::Event &, sf::Window &);

    void pause(sf::Event &);
    void resume(sf::Event &);
public:
    Controller(std::vector<Object* > &);
    void control(sf::RenderWindow &);

    int constrainEdges(Object *o);
    int checkCollision();
    void resolveCollision(Object*,Object*);

    LEVEL getLevel() const;
    HIGHLIGHT getHighlight() const;
};


#endif //PHYSICENGINE_CONTROLLER_H
