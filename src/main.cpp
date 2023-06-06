#include <iostream>
#include "Object.h"
#include "View.h"
#include "Controller.h"
#include "vector"
#include <time.h>
#include <stdlib.h>

#define FRAMERATE 60



int main() {

    srand(time(NULL));

    std::vector<Object*> objects;
    Controller controller(objects);
    View view(objects, controller);

    sf::RenderWindow win(sf::VideoMode(SCREENWIDTH,SCREENHEIGHT), "Engine");
    win.setFramerateLimit(FRAMERATE);

    while(win.isOpen())
    {
        controller.control(win);
        view.present(win);
    }

    return 0;
}
