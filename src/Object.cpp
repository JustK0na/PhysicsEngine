//
// Created by Admin on 16.05.2023.
//

#include "Object.h"


Object::Object()
{
    oldPosition.push_back(0);
    oldPosition.push_back(0);
    currentPosition.push_back(0);
    currentPosition.push_back(0);

    mass=MASS;
    //Forces that are impacting every object

    forces.push_back(0);
    forces.push_back(0);
    //Gravity, Y axis
    forces[1]+=GRAVITYFORCE;
    //Friction

}

std::vector<float> Object::getOldPosition() const
{
    return  oldPosition;
}
std::vector<float> Object::getPosition() const
{
    return currentPosition;
}

std::vector<float> Object::getForces() const
{
    return forces;
}

float Object::getMass()
{
    return  mass;
}
int Object::spawn(int x, int y)
{
    int random1 = rand()%40-20;
    int random2 = rand()%40-20;
    oldPosition[0]=x+random1;
    oldPosition[1]=y+random2;

    currentPosition[0]=x;
    currentPosition[1]=y;


    //Udalo sie stworzyc obiekt
    return 0;
}
void Object::updatePosition(std::vector<float> newPosition)
{
    currentPosition=newPosition;
}
void Object::updateOldPosition(std::vector<float> newPosition) {
    oldPosition=newPosition;
}
void Object::draw(sf::RenderWindow&) const {}






Circle::Circle():radius(SIZE)
{
}
float Circle::getRadius() const
{
    return radius;
}
void Circle::draw(sf::RenderWindow & win) const
{
    sf::CircleShape circ(radius);
    circ.setPosition(getPosition()[0] - radius, getPosition()[1] - radius);
    circ.setFillColor(sf::Color(240,240,240));
    win.draw(circ);
}