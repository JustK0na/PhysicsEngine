//
// Created by Admin on 16.05.2023.
//

#include "View.h"



View::View(std::vector<Object*> &objects):o(objects)
{

}
void View::drawObjects(sf::RenderWindow & win) const
{
    for(unsigned int i=0; i<o.size(); i++)
    {
       /* Circle* circle = dynamic_cast<Circle *>(o[i]);
        if(circle)
        {
            sf::CircleShape circ(circle->getRadius());
            circ.setPosition(sf::Vector2f(o[i]->getPosition()[0]-circle->getRadius(), o[i]->getPosition()[1]-circle->getRadius()));
            circ.setFillColor(sf::Color(240,240,240));
            win.draw(circ);
        }*/
       o[i]->draw(win);

    }
}
void View::present(sf::RenderWindow &win) const
{
    win.clear(sf::Color(0,0,0));
    drawObjects(win);
    win.display();
}

