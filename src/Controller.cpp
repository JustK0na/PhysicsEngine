//
// Created by Admin on 17.05.2023.
//

#include "Controller.h"



Controller::Controller(std::vector<Object *>  &objects):o(objects)
{
    level = MENU;
    state = RUNNING;
    globalTime = 0;
}
LEVEL Controller::getLevel() const
{
    return level;
}
HIGHLIGHT Controller::getHighlight() const
{
    return highlight;
}
STATE Controller::getState() const
{
    return state;
}
void Controller::changeLevel(sf::Event &event, sf::Window &win)
{
    if(level==MENU) {
        if (sf::Mouse::getPosition(win).x >= 512 && sf::Mouse::getPosition(win).x <= 1086) {
            if (sf::Mouse::getPosition(win).y >= 304 && sf::Mouse::getPosition(win).y <= 351) {
                highlight = GRAVITATIONAL;
                //std::cout << "\nFIELD: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    level = GRAVITYFIELD;
                return;
            }
        }
        if (sf::Mouse::getPosition(win).x >= 525.5 && sf::Mouse::getPosition(win).x <= 1070.5) {
            if (sf::Mouse::getPosition(win).y >= 454 && sf::Mouse::getPosition(win).y <= 506) {
                highlight = PLANETARY;
                //std::cout << "\nPLANETARY: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    level = PLANETARYSYSTEM;
                return;
            }

        }

        if (sf::Mouse::getPosition(win).x >= 706.5 && sf::Mouse::getPosition(win).x <= 891, 5) {
            if (sf::Mouse::getPosition(win).y >= 726 && sf::Mouse::getPosition(win).y <= 775) {
                highlight = EXIT1;
                //std::cout << "\nEXIT: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    win.close();
                return;
            }

        }
    }
    if(state==PAUSE_MENU)
    {
        if (sf::Mouse::getPosition(win).x >= 656 && sf::Mouse::getPosition(win).x <= 940) {
            if (sf::Mouse::getPosition(win).y >= 264 && sf::Mouse::getPosition(win).y <= 310) {
                highlight = RESUME;
                //std::cout << "\nRESUME: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    state = RUNNING;
                return;
            }
        }
        if (sf::Mouse::getPosition(win).x >= 657 && sf::Mouse::getPosition(win).x <= 941) {
            if (sf::Mouse::getPosition(win).y >= 389 && sf::Mouse::getPosition(win).y <= 450) {
                highlight = OPTIONS;
               // std::cout << "\nOPTIONS: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    state = PAUSE_OPTIONS;
                return;
            }
        }
        if (sf::Mouse::getPosition(win).x >= 561.5 && sf::Mouse::getPosition(win).x <= 1034.5) {
            if (sf::Mouse::getPosition(win).y >= 526 && sf::Mouse::getPosition(win).y <= 571) {
                highlight = BACK;
                //std::cout << "\nBack: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    state = RUNNING;
                    o.clear();
                    level = MENU;
                }
                return;
            }
        }
        if (sf::Mouse::getPosition(win).x >= 723 && sf::Mouse::getPosition(win).x <= 875) {
            if (sf::Mouse::getPosition(win).y >= 704 && sf::Mouse::getPosition(win).y <= 745) {
                highlight = EXIT2;
               // std::cout << "\nEXIT2: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    win.close();
                return;
            }
        }
    }
    if(state==PAUSE_OPTIONS)
    {
        if(sf::Keyboard::isKeyPressed((sf::Keyboard::Escape)))
            state=PAUSE_MENU;
    }
        highlight = NONE;
        //std::cout << "\nNONE: " << highlight;


}
void Controller::pause()
{
    if(state==RUNNING)
        state = PAUSE_POINTER;
}
void Controller::resume(sf::Event &)
{
    if(state==PAUSE_MENU||state==PAUSE_||state==PAUSE_OPTIONS)
        return;
    state = RUNNING;
}
void Controller::restart(sf::Event & event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        o.clear();
    }
}
void Controller::pausePlay(sf::Event &event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if(state == PAUSE_)
        {
            state = RUNNING;
            return;
        }

        else if (state == RUNNING)
        {
            state = PAUSE_;
            return;
        }

    }
}

void Controller::menu()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        if(state!=PAUSE_MENU) {
            state = PAUSE_MENU;
            return;
        }
        state = RUNNING;
    }
}

void Controller::addObject(sf::Event &event, sf::Window &win)
{
    if(level==MENU)
        return;
    if(state==PAUSE_MENU||state==PAUSE_)
        return;

    if(event.mouseButton.button==sf::Mouse::Left)
    {
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;

        o.push_back(new Circle); //tego tutaj nie może być !!!e

        if(o.back()->spawn(x,y,x,y,globalTime)==0)
        {
            std::cout<<"\nObject has been created: ";
        }
        std::cout<<o.back()->getPosition()[0]<<" "<<o.back()->getPosition()[1];
    }
}
void Controller::setStartingVelocity(sf::Event& event)
{
    if(state==PAUSE_||state==PAUSE_MENU)
        return;
    if(event.mouseButton.button==sf::Mouse::Left) {
        if(o.size()>0) {
            if(o.back()->getTimeOfBirth()==globalTime) {
                float x, y;
                float Vx = (o.back()->getPosition()[0]) - (event.mouseButton.x);
                float Vy = (o.back()->getPosition()[1]) - (event.mouseButton.y);


                x = (o.back()->getPosition()[0]) - Vx / 10;
                y = (o.back()->getPosition()[1]) - Vy / 10;

                std::cout << "\nVx: " << Vx << "    Vy: " << Vy << "   x: " << x << "    y: " << y;
                std::vector<float> oldPosition;
                oldPosition.push_back(x);
                oldPosition.push_back(y);
                o.back()->updateOldPosition(oldPosition);
            }
        }
    }
}
void Controller::addForces(Object *o)
{
    //Gravity Force:
    std::vector<float> ForceY;
    ForceY.push_back(0);
    ForceY.push_back(0);

    float gravity;
    float G = (6.6743 * pow(10, -11));
    float M = 5.97219 * pow(10, 24);
    float R = 6.3781 * pow(10, 6);


    gravity = G * M * o->getMass()/pow(R,2);
    ForceY.at(1)=+gravity;
    //std::cout<<"Gravity: "<<gravity<<std::endl;

    o->updateForces(ForceY, 1);


}
std::vector<float> Controller::calculateAcceleration(Object *o)
{
    std::vector<float> acceleration;
    acceleration.push_back(0);
    acceleration.push_back(0);

    acceleration.at(0) = (o->getForces()[0]*FRAMERATE)/o->getMass();
    acceleration.at(1) = (o->getForces()[1]*FRAMERATE)/o->getMass();

    //std::cout<<"\t\t\t"<<acceleration.at(1)<<std::endl;

    return acceleration;

}
void Controller::changePosition(Object *o)
{
    // calculate velocity
    float velocityx, velocityy;
    velocityx = ( o->getPosition()[0]-o->getOldPosition()[0]);
    velocityy = ( o->getPosition()[1]-o->getOldPosition()[1]);

    //set old position to curren posiotion
    o->updateOldPosition(o->getPosition());

    //calculate new position with dt = 1, update by every frame;
    float newPositionx, newPositiony;

    newPositionx=o->getPosition()[0]+velocityx+((calculateAcceleration(o)[0]/pow(FRAMERATE,2)));
    newPositiony=o->getPosition()[1]+velocityy+((calculateAcceleration(o)[1]/pow(FRAMERATE,2)));

    //set new position
    std::vector<float> newPosition;
    newPosition.push_back(newPositionx);
    newPosition.push_back(newPositiony);
    o->updatePosition(newPosition);
    //std::cout<<"\nPositionX: "<< o->getPosition()[0]<<"\tPositionY: "<<o->getPosition()[1]<<"\tVelocity X: "<<velocityx<<"\tVelocity Y: "<<velocityy<<"\tAcceleration Y: "<<((calculateAcceleration(o)[1])/FRAMERATE);

}
void Controller::update()
{
    if(state!=RUNNING)
        return;

    for(unsigned int i = 0; i<o.size(); i++)
    {
        if(globalTime>1000000)
            globalTime = 0;
        globalTime++;
        addForces(o[i]);
        changePosition(o[i]);
        constrainEdges(o[i]);
        checkCollision();
        //std::cout<<"\n...";
    }
}
int Controller::constrainEdges(Object *o)
{
        if(o->getPosition()[1]+o->info()[0]>=SCREENHEIGHT)
        {
            float Vy = abs(o->getPosition()[1]-o->getOldPosition()[1]);

            std::vector<float> newPosition{o->getPosition()[0],SCREENHEIGHT-o->info()[0]};
            std::vector<float> oldPosition{o->getOldPosition()[0],SCREENHEIGHT-o->info()[0]+Vy};
            o->updatePosition(newPosition);
            o->updateOldPosition(oldPosition);
            //std::cout<<"\n\t\t\t\tConstarain";
        }
        if(o->getPosition()[1]-o->info()[0]<=0)
        {
            float Vy = abs(o->getPosition()[1]-o->getOldPosition()[1]);

            std::vector<float> newPosition{o->getPosition()[0],0+o->info()[0]};
            std::vector<float> oldPosition{o->getOldPosition()[0],0+o->info()[0]-Vy};
            o->updatePosition(newPosition);
            o->updateOldPosition(oldPosition);
           // std::cout<<"\n\t\t\t\tConstarain";
        }
        if(o->getPosition()[0]+o->info()[0]>=SCREENWIDTH)
        {
            float Vx = abs(o->getPosition()[0]-o->getOldPosition()[0]);

            std::vector<float> newPosition{SCREENWIDTH-o->info()[0],o->getPosition()[1]};
            std::vector<float> oldPosition{SCREENWIDTH-o->info()[0]+Vx,o->getOldPosition()[1]};
            o->updatePosition(newPosition);
            o->updateOldPosition(oldPosition);
            //std::cout<<"\n\t\t\t\tConstarain";
        }
        if(o->getPosition()[0]-o->info()[0]<=0)
        {
            float Vx = abs(o->getPosition()[0]-o->getOldPosition()[0]);

            std::vector<float> newPosition{0+o->info()[0],o->getPosition()[1]};
            std::vector<float> oldPosition{0+o->info()[0]-Vx,o->getOldPosition()[1]};
            o->updatePosition(newPosition);
            o->updateOldPosition(oldPosition);
           // std::cout<<"\n\t\t\t\tConstarain";
        }
    return  0;
}

int Controller::checkCollision()
{
    for(unsigned int i=0; i<o.size(); i++)
    {
        for(unsigned int j=0; j<o.size(); j++) {
            if(i!=j){
                //Policz dlugosc wektora pomiedzy srodkami kol
                float distance = sqrt(pow((o[i]->getPosition()[0] - o[j]->getPosition()[0]), 2) +
                        pow((o[i]->getPosition()[1] - o[j]->getPosition()[1]), 2));
                 //porownaj z dlugoscia promieni
                float radiusTotal = o[i]->info()[0] + o[j]->info()[0];

                 //jesli dlugosc wektora mniejsza/rowna sumie dlugosci promieni oblicz kolizje
                 if (distance <= radiusTotal) {
                   //  resolveCollision(o[i],o[j]);
                    std::cout<<i<<" with "<<j<< "   COLLISION!!!\n";
                }
            }
        }
    }
    return 0;
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
                pause();
                addObject(event, win);
                break;
            case sf::Event::MouseButtonReleased:
                setStartingVelocity(event);
                resume(event);
                break;
            case sf::Event::KeyPressed:
                restart(event);
                pausePlay(event);
                menu();
                break;
            default:
                break;
        }
    }
    changeLevel(event,win);
    update();
}