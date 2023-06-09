//
// Created by Admin on 17.05.2023.
//

#include "Controller.h"



Controller::Controller(std::vector<Object *>  &objects):o(objects)
{
    level = MENU;
    state = RUNNING;
    globalTime = 0;
    G = (6.6743 * pow(10, -11));
    M = 5.97219 * pow(10, 24);
    R = 6.3781 * pow(10, 6);
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
float Controller::getGravitationalConstant() const {
    return G;
}
float Controller::getPlanetRadius() const
{
    return R;
}
float Controller::getPlanetMass() const{
    return M;
}

void Controller::changeGravitationalConstant (float gravitationalConstant){
    G=gravitationalConstant;
}
void Controller::changePlanetRadius(float radius){
    R=radius;
}
void Controller::changePlanetMass(float mass)
{
    M = mass;
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
        if (sf::Mouse::getPosition(win).x >= 341.4 && sf::Mouse::getPosition(win).x <= 1115.4) {
            if (sf::Mouse::getPosition(win).y >= 207 && sf::Mouse::getPosition(win).y <= 233) {
                highlight = GRAVITATIONALCONSTANT;
                 //std::cout << "\nGravitational constant: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    float a;
                    std::cout<<"\nWrite new gravitational constant: ";
                    std::cin>>a;
                    a = a * pow(10, -11);
                    changeGravitationalConstant(a);
                }

                return;
            }
        }
        if (sf::Mouse::getPosition(win).x >= 342.4 && sf::Mouse::getPosition(win).x <= 887.4) {
            if (sf::Mouse::getPosition(win).y >= 507 && sf::Mouse::getPosition(win).y <= 533) {
                highlight = PLANETMASS;
                 //std::cout << "\nPlanet MAss: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    float a;
                    std::cout<<"\nWrite new Planet's mass: ";
                    std::cin>>a;
                    a=a * pow(10, 24);
                    changePlanetMass(a);
                }

                return;
            }
        }
        if (sf::Mouse::getPosition(win).x >= 342.4 && sf::Mouse::getPosition(win).x <= 906.4) {
            if (sf::Mouse::getPosition(win).y >= 357 && sf::Mouse::getPosition(win).y <= 383) {
                highlight = PLANETRADIUS;
                 //std::cout << "\nPlanetRadiiuss: " << highlight;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    float a;
                    std::cout<<"\nWrite new Planet's radius: ";
                    std::cin>>a;
                    a = a * pow(10, 6);
                    changePlanetRadius(a);
                }
                return;
            }
        }
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
        changeGravitationalConstant((6.6743 * pow(10, -11)));
        changePlanetMass(5.97219 * pow(10, 24));
        changePlanetRadius(6.3781 * pow(10, 6));
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
    if(state==PAUSE_MENU||state==PAUSE_||state==PAUSE_OPTIONS)
        return;

    if(event.mouseButton.button==sf::Mouse::Left)
    {
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;


        o.push_back(new Circle);

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
                     resolveCollision(o[i],o[j]);
                     //std::cout<<i<<" with "<<j<< "   COLLISION!!!\n";
                }
            }
        }
    }
    return 0;
}
void Controller::resolveCollision(Object *obj1, Object *obj2) {

/* ################## solving for obj 1 #############*/
    std::vector<float> circlesCenter; //Vector that connects centres of objects(circles)
    float Cx1, Cy1;
    Cx1=(obj1->getPosition()[0]-obj2->getPosition()[0]);
    Cy1=(obj1->getPosition()[1]-obj2->getPosition()[1]);
    circlesCenter.push_back(Cx1);
    circlesCenter.push_back(Cy1);
    //std::cout<<"\nCircle centre: "<<obj1->getPosition()[0]<<", "<<obj1->getPosition()[1];
    //std::cout<<"\tVector: "<<circlesCenter.at(0)<<", "<<circlesCenter.at(1);

    std::vector<float> perpendicular; //Vector that is perpendicular to vector of circles centres, and have beginning in one's centre
    float Px2,Py2;
    if(circlesCenter.at(1)!=0) {
        Px2 = 1;
        Py2 = -(circlesCenter.at(0)/ circlesCenter.at(1));
        perpendicular.push_back(Px2);
        perpendicular.push_back(Py2);
    }
    else{
        Px2=-(circlesCenter.at(1)/circlesCenter.at(0));
        Py2=1;
        perpendicular.push_back(Px2);
        perpendicular.push_back(Py2);
    }
   // std::cout<<"\nVector perpandicular: "<<perpendicular.at(0)<<", "<<perpendicular.at(1);

    std::vector<float> projection; //linear projection of velocity onto perpendicular vector
    float Px3, Py3;
    float Vx1, Vy1;
    Vx1=obj1->getPosition()[0]-obj1->getOldPosition()[0];
    Vy1=obj1->getPosition()[1]-obj1->getOldPosition()[1];



    //Momentum equation, scaling vectors accordingly
    float Vx2, Vy2; //scalar
    Vx2 = obj2->getPosition()[0]-obj2->getOldPosition()[0];
    Vy2 = obj2->getPosition()[1]-obj2->getOldPosition()[1];
    float VxMomentum, VyMomentum; //scalar
    VxMomentum = (Vx1*(obj1->getMass()-obj2->getMass())+2*obj2->getMass()*Vx2)/(obj1->getMass()+obj2->getMass());
    VyMomentum = (Vy1*(obj1->getMass()-obj2->getMass())+2*obj2->getMass()*Vy2)/(obj1->getMass()+obj2->getMass());
    
    Vx1 = VxMomentum;
    Vy1 = VyMomentum;


    //std::cout<<"\nVelocity: "<<Vx1<<", "<<Vy1;

    Px3=((Vx1*perpendicular.at(0)+Vy1*perpendicular.at(1))/
            (perpendicular.at(0)*perpendicular.at(0)+perpendicular.at(1)*perpendicular.at(1)))*perpendicular.at(0);
    Py3=((Vx1*perpendicular.at(0)+Vy1*perpendicular.at(1))/
         (perpendicular.at(0)*perpendicular.at(0)+perpendicular.at(1)*perpendicular.at(1)))*perpendicular.at(1);

    projection.push_back(Px3+obj1->getPosition()[0]);
    projection.push_back(Py3+obj1->getPosition()[1]);

    //std::cout<<"\nVector projection: "<<projection.at(0)<<", "<<projection.at(1);
    std::vector<float> newVelocity;
    float FinalVxPoint, FinalVyPoint; //vector

        FinalVxPoint = 2*(projection.at(0))-(obj1->getPosition()[0]+Vx1);
    FinalVyPoint = 2*(projection.at(1))-(obj1->getPosition()[1]+Vy1);

    newVelocity.push_back(FinalVxPoint);
    newVelocity.push_back(FinalVyPoint);

    //std::cout<<"\nOld position: "<<obj1->getPosition()[0]<<", "<<obj1->getPosition()[1];
    //std::cout<<"\tPosition:  "<<FinalVxPoint<<", "<<FinalVyPoint;
    obj1->updateOldPosition(obj1->getPosition());
    obj1->updatePosition(newVelocity);
    
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