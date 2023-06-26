//
// Created by Admin on 16.05.2023.
//

#include "View.h"



View::View(std::vector<Object*> &objects, Controller &controller):o(objects),c(controller)
{
    if(!Oxproto.loadFromFile("../graphics/fonts/0xproto/0xProto-Regular.ttf"))
        std::cout<<"\nFAILED TO LOAD 0xproto FONT";
    if(!retrogastroll.loadFromFile("../graphics/fonts/retrogastroll/Retro Gastroll.ttf"))
        std::cout<<"\nFAILED TO LOAD RetroGastroll FONT";
    if(!openingHours.loadFromFile("../graphics/fonts/openinghours/OpeningHoursMonoVF.ttf"))
        std::cout<<"\nFAILED TO LOAD OpeningHours FONT";
}
/*sf::Text View::createText(char Text[], sf::Font font, sf::Color fillColor, int size, sf::Color outlineColor,
                      int outlinethicnkess, float posX, float posY) const
{
    sf::Text text(Text ,font);
    text.setFillColor(fillColor);
    text.setCharacterSize(size);
    text.setOutlineColor(outlineColor);
    text.setOutlineThickness(outlinethicnkess);
    text.setPosition(posX, posY);
    return text;

}*/
void View::Menu(sf::RenderWindow &win) const
{
    if(c.getLevel()!=MENU)
        return ;


    //  Program Name
    sf::Text sphereDrop("Sphere Drop", retrogastroll);
    sphereDrop.setFillColor(sf::Color(204, 198, 82));
    sphereDrop.setCharacterSize(55);
    sphereDrop.setPosition(SCREENWIDTH/2 - sphereDrop.getGlobalBounds().width/2,100);
    win.draw(sphereDrop);


    //  Mode1: Gravitational Field
    sf::Text gravitationalField("Gravitational Field", retrogastroll);
    if(c.getHighlight()==GRAVITATIONAL)
        gravitationalField.setFillColor(sf::Color::Red);
    else
        gravitationalField.setFillColor(sf::Color(235, 232, 176));

    gravitationalField.setCharacterSize(40);
    gravitationalField.setPosition(SCREENWIDTH/2 - gravitationalField.getGlobalBounds().width/2,300);
    win.draw(gravitationalField);


    //  Mode2: Planetary System

    sf::Text planetarySystem("Planetary System", retrogastroll);
    if(c.getHighlight()==PLANETARY)
        planetarySystem.setFillColor(sf::Color::Red);
    else
        planetarySystem.setFillColor(sf::Color(235, 232, 176));
    planetarySystem.setCharacterSize(40);
    planetarySystem.setPosition(SCREENWIDTH/2 - planetarySystem.getGlobalBounds().width/2,450);
   // std::cout<<"\nplanetary  x,y,height,width: "<<planetarySystem.getGlobalBounds().left<<", "<<planetarySystem.getGlobalBounds().top<<", "
   //         <<planetarySystem.getGlobalBounds().height<<", "<<planetarySystem.getGlobalBounds().width;
    win.draw(planetarySystem);



    //  Exit

    sf::Text exit("Exit", retrogastroll);
    if(c.getHighlight()==EXIT1)
        exit.setFillColor(sf::Color::Red);
    else
        exit.setFillColor(sf::Color(235, 232, 176));
    exit.setCharacterSize(55);
    exit.setPosition(SCREENWIDTH/2 - exit.getGlobalBounds().width/2,720);
    win.draw(exit);



}
void View::menuPause(sf::RenderWindow & win) const
{
    if(c.getState()!=PAUSE_MENU)
        return;
    if(c.getLevel()!=GRAVITYFIELD)
        return;
    int sizeX = 700, sizeY = 800;
    sf::RectangleShape popup(sf::Vector2f(sizeX,sizeY));
    popup.setPosition(SCREENWIDTH/2-sizeX/2, 50);
    popup.setFillColor(sf::Color(123,90,200,150));
    win.draw(popup);

    sf::CircleShape circle(40);
    circle.setFillColor(sf::Color(123,90,200,150));
    circle.setPosition(popup.getGlobalBounds().left-40, popup.getGlobalBounds().top-40);
    win.draw(circle);
    circle.setPosition(popup.getGlobalBounds().left+popup.getGlobalBounds().width-40,
                       popup.getGlobalBounds().top+popup.getGlobalBounds().height-40);
    win.draw(circle);
    circle.setPosition(popup.getGlobalBounds().left-40,
                       popup.getGlobalBounds().top+popup.getGlobalBounds().height-40);
    win.draw(circle);
    circle.setPosition(popup.getGlobalBounds().left+popup.getGlobalBounds().width-40,
                       popup.getGlobalBounds().top-40);
    win.draw(circle);

    sf::Text sphereDrop("Sphere Drop", retrogastroll);
    sphereDrop.setFillColor(sf::Color(204, 198, 82));
    sphereDrop.setCharacterSize(55);
    sphereDrop.setPosition( (SCREENWIDTH/2-sizeX/2) + (popup.getGlobalBounds().width/2) - (sphereDrop.getGlobalBounds().width/2),100);
    win.draw(sphereDrop);

    sf::Text resume("Resume", retrogastroll);
    if(c.getHighlight()==RESUME)
        resume.setFillColor(sf::Color::Red);
    else
        resume.setFillColor(sf::Color(235, 232, 176));
    resume.setCharacterSize(45);
    resume.setPosition( (SCREENWIDTH/2-sizeX/2) + (popup.getGlobalBounds().width/2) - (resume.getGlobalBounds().width/2),
                      sphereDrop.getGlobalBounds().top+sphereDrop.getGlobalBounds().height+75);
    win.draw(resume);

    sf::Text options("Options", retrogastroll);
    if(c.getHighlight()==OPTIONS)
        options.setFillColor(sf::Color::Red);
    else
        options.setFillColor(sf::Color(235, 232, 176));
    options.setCharacterSize(45);
    options.setPosition( (SCREENWIDTH/2-sizeX/2) + (popup.getGlobalBounds().width/2) - (options.getGlobalBounds().width/2),
                        resume.getGlobalBounds().top+resume.getGlobalBounds().height+75);

    win.draw(options);

    sf::Text back("Back to menu", retrogastroll);
    if(c.getHighlight()==BACK)
        back.setFillColor(sf::Color::Red);
    else
        back.setFillColor(sf::Color(235, 232, 176));
    back.setCharacterSize(45);
    back.setPosition( (SCREENWIDTH/2-sizeX/2) + (popup.getGlobalBounds().width/2) - (back.getGlobalBounds().width/2),
                         options.getGlobalBounds().top+options.getGlobalBounds().height+75);

    win.draw(back);



    sf::Text exit("Exit", retrogastroll);
    if(c.getHighlight()==EXIT2)
        exit.setFillColor(sf::Color::Red);
    else
        exit.setFillColor(sf::Color(235, 232, 176));
    exit.setCharacterSize(45);
    exit.setPosition( (SCREENWIDTH/2-sizeX/2) + (popup.getGlobalBounds().width/2) - (exit.getGlobalBounds().width/2),
                            popup.getGlobalBounds().top+popup.getGlobalBounds().height-150);
    //std::cout<<"\nexit2  x,y,height,width: "<<exit.getGlobalBounds().left<<", "<<exit.getGlobalBounds().top<<", "
     //        <<exit.getGlobalBounds().height<<", "<<exit.getGlobalBounds().width;
    win.draw(exit);

}
void View::options(sf::RenderWindow &win) const
{
    if(c.getState()!=PAUSE_OPTIONS)
        return;


    sf::RectangleShape rect(sf::Vector2f(1000, 700));
    rect.setPosition(SCREENWIDTH/2-(rect.getGlobalBounds().width/2), SCREENHEIGHT/2-(rect.getGlobalBounds().height/2));
    rect.setFillColor(sf::Color(123,90,200,150));

    sf::Text gravityConst("Gravitational constant: "+std::to_string(c.getGravitationalConstant()* pow(10,11))+"*10^(-11)" , Oxproto);
    if(c.getHighlight()==GRAVITATIONALCONSTANT)
        gravityConst.setFillColor(sf::Color::Red);
    else
        gravityConst.setFillColor(sf::Color(186, 65, 9));
    gravityConst.setCharacterSize(30);
    gravityConst.setPosition((rect.getGlobalBounds().left+rect.getGlobalBounds().width)/2-gravityConst.getGlobalBounds().width/2.5,200);
    win.draw(gravityConst);
    //std::cout<<"\ngravity const: X,Y, width, height "<<gravityConst.getGlobalBounds().left<<", "<<gravityConst.getGlobalBounds().top<<", "<<gravityConst.getGlobalBounds().width
    //    <<", "<<gravityConst.getGlobalBounds().height;

    sf::Text planetRadius("Planet Radius: "+std::to_string(c.getPlanetRadius()* pow(10,-6))+"*10^(6)" , Oxproto);
    if(c.getHighlight()==PLANETRADIUS)
        planetRadius.setFillColor(sf::Color::Red);
    else
        planetRadius.setFillColor(sf::Color(186, 65, 9));
    planetRadius.setCharacterSize(30);
    planetRadius.setPosition((rect.getGlobalBounds().left+rect.getGlobalBounds().width)/2-gravityConst.getGlobalBounds().width/2.5,350);
    win.draw(planetRadius);
    //std::cout<<"\nplanet radius: X,Y, width, height "<<planetRadius.getGlobalBounds().left<<", "<<planetRadius.getGlobalBounds().top<<", "<<planetRadius.getGlobalBounds().width
    //         <<", "<<planetRadius.getGlobalBounds().height;

    sf::Text planetMass("Planet Mass: "+std::to_string(c.getPlanetMass()* pow(10,-24))+"*10^(24)" , Oxproto);
    if(c.getHighlight()==PLANETMASS)
        planetMass.setFillColor(sf::Color::Red);
    else
        planetMass.setFillColor(sf::Color(186, 65, 9));
    planetMass.setCharacterSize(30);
    planetMass.setPosition((rect.getGlobalBounds().left+rect.getGlobalBounds().width)/2-gravityConst.getGlobalBounds().width/2.5,500);
    win.draw(planetMass);
    //std::cout<<"\nplanet mass: X,Y, width, height "<<planetMass.getGlobalBounds().left<<", "<<planetMass.getGlobalBounds().top<<", "<<planetMass.getGlobalBounds().width
    //         <<", "<<planetMass.getGlobalBounds().height;


    win.draw(rect);
}
void View::drawPause(sf::RenderWindow &win) const
{
    if(c.getLevel()!=MENU) {
        if (c.getState() != PAUSE_)
            return;
        sf::RectangleShape rect(sf::Vector2f(75, 300));
        rect.setFillColor(sf::Color(67, 67, 92,150));
        rect.setPosition((SCREENWIDTH/2)-rect.getGlobalBounds().width, (SCREENHEIGHT/2)-(rect.getGlobalBounds().height/2));
        win.draw(rect);
        rect.setPosition((SCREENWIDTH/2)+rect.getGlobalBounds().width, (SCREENHEIGHT/2)-(rect.getGlobalBounds().height/2));
        win.draw(rect);

    }
}
void View::drawObjects(sf::RenderWindow & win) const
{
    for(unsigned int i=0; i<o.size(); i++)
    {
       o[i]->draw(win);

    }
}
void View::drawPointer(sf::RenderWindow &win) const
{
    if(c.getState()!=PAUSE_POINTER)
        return;

    if(o.size()>0) {

        float Vx = (o.back()->getPosition()[0]) - (sf::Mouse::getPosition(win).x);
        float Vy = (o.back()->getPosition()[1]) - (sf::Mouse::getPosition(win).y);

        float length;
        length = sqrt(((Vx * Vx) + (Vy * Vy)));


        float tan = (Vy/Vx);
        float degree = 0;
        if(Vx>=0)
            degree = (180/(M_PI))*atan(tan);
        else if(Vx<0)
            degree = (180/(M_PI))*atan(tan)+180;


        //std::cout<<"\nDegree: "<<degree;


        sf::Text VelocityX("Vx: "+std::to_string((Vx/10))+", " , Oxproto);
        VelocityX.setFillColor(sf::Color::White);
        VelocityX.setCharacterSize(20);
        VelocityX.setOutlineColor(sf::Color::Red);
        VelocityX.setOutlineThickness(1);
        win.draw(VelocityX);
       // sf::Text VelocityX = createText("POP", Oxproto, sf::Color::White, 20,
       //                                 sf::Color::Red, 1,0,0);

        sf::Text VelocityY("Vy: "+std::to_string((Vy/10)), Oxproto);
        VelocityY.setFillColor(sf::Color::White);
        VelocityY.setCharacterSize(20);
        VelocityY.setOutlineThickness(1);
        VelocityY.setOutlineColor(sf::Color::Red);
        VelocityY.setPosition(VelocityX.getGlobalBounds().left+VelocityX.getGlobalBounds().width+5,0);
        win.draw(VelocityY);


        sf::RectangleShape pointer(sf::Vector2f(length, 1));
        pointer.setPosition(o.back()->getPosition()[0], o.back()->getPosition()[1]);
        pointer.rotate(degree);
        pointer.setFillColor(sf::Color::Red);

        sf::RectangleShape arrow1(sf::Vector2f(20,1));
        arrow1.setPosition(pointer.getPosition().x+Vx, pointer.getPosition().y+Vy);
        arrow1.rotate(degree+135);
        arrow1.setFillColor(sf::Color::Red);

        sf::RectangleShape arrow2(sf::Vector2f(20,1));
        arrow2.setPosition(pointer.getPosition().x+Vx, pointer.getPosition().y+Vy);
        arrow2.rotate(degree-135);
        arrow2.setFillColor(sf::Color::Red);


        win.draw(arrow1);
        win.draw(arrow2);
        win.draw(pointer);
    }

}
void View::present(sf::RenderWindow &win) const
{
    win.clear(sf::Color(0,0,0));

    drawObjects(win);
    drawPointer(win);
    Menu(win);
    options(win);
    menuPause(win);
    drawPause(win);
    win.display();
}

