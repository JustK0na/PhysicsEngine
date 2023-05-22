//
// Created by Admin on 17.05.2023.
//

#include "Controller.h"



Controller::Controller(std::vector<Object *>  &objects):o(objects)
{

}

void Controller::addObject(sf::Event &event)
{
    if(event.mouseButton.button==sf::Mouse::Left)
    {
        o.push_back(new Circle);
        if(o.back()->spawn(event.mouseButton.x,event.mouseButton.y)==0)
        {
            std::cout<<"\nObject has been created: ";
        }
        std::cout<<o.back()->getPosition()[0]<<" "<<o.back()->getPosition()[1];
    }
}
std::vector<float> Controller::acceleration(Object *o)
{
    float accelerationx=0, accelerationy=0;
    std::vector<float> acceleration;
    acceleration.push_back(accelerationx);
    acceleration.push_back(accelerationy);

    //All forces that impact object in x and y axis divided by mass give acceleration in that direction
    acceleration[1]=o->getForces()[1]/o->getMass();


    return  acceleration;


}

void Controller::solver(Object *o, float dt)
{

    if(constrain(o))
        return;


    // calculate velocity
    float velocityx, velocityy;
    velocityx = 0.995 *( o->getPosition()[0]-o->getOldPosition()[0]);
    velocityy = 0.995*(o->getPosition()[1]-o->getOldPosition()[1]);
    //set old position to curren posiotion

    o->updateOldPosition(o->getPosition());

    //calculate new position with dt = 1, update by every frame;
    float newPositionx, newPositiony;

    newPositionx=o->getPosition()[0]+velocityx+(acceleration(o)[0]);
    newPositiony=o->getPosition()[1]+velocityy+(acceleration(o)[1]);


    //set new position
    std::vector<float> newPosition;
    newPosition.push_back(newPositionx);
    newPosition.push_back(newPositiony);
    o->updatePosition(newPosition);


    //Zachowują się dziwnie bo obiekty nie zwalniają lecąc do góry
}
void Controller::update()
{
    for(unsigned int i =0; i<o.size(); i++)
    {
        solver(o[i],1);
        std::cout<<"\nVx: "<<o[i]->getPosition()[0]-o[i]->getOldPosition()[0]<<"\t Oldx: "<<o[i]->getOldPosition()[0]<<"    Curx: "<<o[i]->getPosition()[0];
    }
}
int Controller::constrain(Object *o)
{

        if(o->getPosition()[1]+30>720)  //screen height
        {
            float Vy = o->getPosition()[1]-o->getOldPosition()[1];

            std::vector<float> newPosition{o->getPosition()[0],720-SIZE};
            std::vector<float> oldPosition{o->getOldPosition()[0],720-SIZE+Vy};
            o->updatePosition(newPosition);
            o->updateOldPosition(oldPosition);
            std::cout<<"\n\t\t\t\tConstarain";
           return 1;
        }
        if(o->getPosition()[1]-30<0)
        {
            float Vy = o->getPosition()[1]-o->getOldPosition()[1];

            std::vector<float> newPosition{o->getPosition()[0],0+SIZE};
            std::vector<float> oldPosition{o->getOldPosition()[0],0+SIZE-Vy};
            o->updatePosition(newPosition);
            o->updateOldPosition(oldPosition);
            std::cout<<"\n\t\t\t\tConstarain";
            return 1;
        }
        if(o->getPosition()[0]+30>1080)
        {
            float Vx = o->getPosition()[0]-o->getOldPosition()[0];

            std::vector<float> newPosition{1080-SIZE,o->getPosition()[1]};
            std::vector<float> oldPosition{1080-SIZE+Vx,o->getOldPosition()[1]};
            o->updatePosition(newPosition);
            o->updateOldPosition(oldPosition);
            std::cout<<"\n\t\t\t\tConstarain";
           return 1;
        }
        if(o->getPosition()[0]-30<0)
        {
            float Vx = o->getPosition()[0]-o->getOldPosition()[0];

            std::vector<float> newPosition{0+SIZE,o->getPosition()[1]};
            std::vector<float> oldPosition{0+SIZE+Vx,o->getOldPosition()[1]};
            o->updatePosition(newPosition);
            o->updateOldPosition(oldPosition);
            std::cout<<"\n\t\t\t\tConstarain";
           return 1;
        }
    return  0;
}
void Controller::control(sf::RenderWindow &win)
{
    sf::Event event;
    while (win.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                win.close();
                break;
            case sf::Event::MouseButtonPressed:
                addObject(event);
                break;

            default:
                break;
        }
    }
    update();
}