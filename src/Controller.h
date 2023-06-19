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
    PAUSE_POINTER,
    PAUSE_,
    PAUSE_MENU,
    PAUSE_OPTIONS
};
enum HIGHLIGHT{
    GRAVITATIONAL,
    PLANETARY,
    EXIT1,
    RESUME,
    OPTIONS,
    BACK,
    EXIT2,

    NONE
};
class Controller {
    std::vector<Object* >& o;
    LEVEL level;
    HIGHLIGHT highlight;
    STATE state;
    int globalTime;

    void addObject(sf::Event &, sf::Window &);
    void setStartingVelocity(sf::Event &);

    void addForces(Object *);

    std::vector<float> calculateAcceleration(Object *   );

    int constrainEdges(Object *o);

    void changePosition(Object *);
    void changeLevel(sf::Event &, sf::Window &);

    int checkCollision();
    void resolveCollision(Object*,Object*);

    void pause();
    void resume(sf::Event &);

    void restart(sf::Event &);

    void pausePlay(sf::Event &);

    void menu();

    void update();

public:
    Controller(std::vector<Object* > &);
    void control(sf::RenderWindow &);




    LEVEL getLevel() const;
    HIGHLIGHT getHighlight() const;
    STATE getState() const;
    std::vector<float> getMousePosition() const;
};


#endif //PHYSICENGINE_CONTROLLER_H
