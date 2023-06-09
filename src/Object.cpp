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


    forces.push_back(0);
    forces.push_back(0);

    timeOfBirth = 0;

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

float Object::getMass() const
{
    return  mass;
}
int Object::getTimeOfBirth() const {
    return timeOfBirth;
}
int Object::spawn(int x, int y, int oldx, int oldy, int time)
{
    timeOfBirth = time;
    int random1 = rand()%20-10;
    int random2 = rand()%20-10;
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
void Object::updateForces(std::vector<float> forcesChange, int axis)
{
    forces.at(axis) = forcesChange[axis];
}


void Object::draw(sf::RenderWindow&) const {}
std::vector<float> Object::info() const {
    std::vector<float> i_nfo;
    i_nfo.push_back(0);
    return i_nfo;
}





Circle::Circle():radius(SIZE)
{
}
std::vector<float>  Circle::info() const
{
    std::vector<float> info;
    info.push_back(radius);
    return info;
}
void Circle::draw(sf::RenderWindow & win) const
{
    sf::CircleShape circ(radius);
    circ.setPosition(getPosition()[0] - radius, getPosition()[1] - radius);
    circ.setFillColor(sf::Color(240,240,240));
    win.draw(circ);
}