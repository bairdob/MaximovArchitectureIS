#include <iostream>
#include <cmath>
#include <iomanip> // setw()
#include "pid.cpp"
#include "engine.cpp"
#include "bear.cpp"
#include "flying_bear.cpp"

#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    sf::Vector2f windowSize(800, 600);
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SFML works!");

    Texture texture;
    texture.loadFromFile("img/pooh.png");
    Sprite pooh;
    pooh.setTexture(texture);
    pooh.setScale(0.2, 0.2);
    pooh.setPosition(100,400);

    const float dt = 0.1; // s
    FlyingBear Pooh(1, 10); //(mass, duploHeight)
      
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        {Pooh.fly_up(dt);
        pooh.move(0, -globalHeight*0.00000000000001);
         }
        if (abs(Pooh.getHollowHeight() - Pooh.getHeight()) < 0.1) Pooh.eat(dt);
        if (abs(Pooh.getMass() - Pooh.getMaxMass()) < 0.01) Pooh.fly_down_extra(dt);
        std::cout << globalHeight << std::endl;

        pooh.move(0, -globalHeight*0.01);

        window.draw(pooh);
        

        window.clear();
        window.draw(pooh);
        window.display();
        }
    

    return 0;
}