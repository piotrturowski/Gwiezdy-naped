#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct position
{
    int x;
    int y;
};

class Star
{
public:
    int x;
    int y;
    int sx;
    int sy;
    float z;
    float zz;
    float big;
    static int number;
    sf::CircleShape shape;
    Star()
    {
        shape = sf::CircleShape(1.f);
        number++;
        shape.setFillColor(sf::Color::White);
        x = (rand() % 600) - 300;
        y = (rand() % 600) - 300;
        z = rand() % 50;
        zz= z / 1.1;
        update();
    }

    void endwiondow()
    {
        if(z<= 0)
        {
            x = (rand() % 600) - 300;
            y = (rand() % 600) - 300;
            z = 50;
        }

    }

    void foward()
    {
        z = (z - 0.07);//zblizenie gwiazd
        big = 4 /z;

        update();

        //std::cout << big << std::endl << big1 << std::endl;
        endwiondow();
        shape.setScale(big,big);
    }

    void update()
    {
        sx = x/z + 300;
        sy = y/z + 300;
        shape.setPosition(sx,sy);

    }
};

int Star::number = 0;

int main()
{
    srand (time(NULL));
    position window;
    window.x = 600;
    window.y = 600;
    Star Stars[500];
    sf::RenderWindow Window(sf::VideoMode(window.x, window.y), "Galaxy Jump!");
    sf::Event event;
    Window.setFramerateLimit(30);
    while (Window.isOpen())
    {
//input
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window.close();
        }
//logic
        for(int i = 0; i <= Star::number-1 ; i++)
        {
            Stars[i].foward();
        }

//graphic
        Window.clear();
        for(int i = 0; i <= Star::number-1 ; i++)
        {
            Window.draw(Stars[i].shape);
        }
        Window.display();
    }

    return 0;
}
