//
// Created by Admin on 16.05.2023.
//

#ifndef PHYSICENGINE_OBJECT_H
#define PHYSICENGINE_OBJECT_H
#define SIZE 30
#define  MASS 10
#define GRAVITYFORCE 10
#define FRICTION 0.999

#include "vector"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <time.h>
#include <stdlib.h>

class Object {

    std::vector<float>  oldPosition;
    std::vector<float>  currentPosition;
    std::vector<float>  forces;
    float mass;
public:
    Object();
    std::vector<float> getOldPosition() const ;
    std::vector<float> getPosition() const ;
    std::vector<float> getForces() const ;
    float getMass() const;
    virtual std::vector<float> info()  const;

    virtual void draw(sf::RenderWindow&) const;


    void updatePosition(std::vector<float>);
    void updateOldPosition(std::vector<float>);

    int spawn(int x, int y);


};
class Circle: public Object
{
    float radius;
public:
    Circle();
    void draw(sf::RenderWindow &) const;
    std::vector<float> info() const;
};

#endif //PHYSICENGINE_OBJECT_H
