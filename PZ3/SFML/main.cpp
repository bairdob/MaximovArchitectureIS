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
    sf::CircleShape circle(10.f);
    circle.setOrigin(-100, -580);
    //circle.setOrigin(0, 0);
    circle.setFillColor(sf::Color::Green);

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
        Pooh.fly_up(dt);
        if (abs(Pooh.getHollowHeight() - Pooh.getHeight()) < 0.1) Pooh.eat(dt);
        if (abs(Pooh.getMass() - Pooh.getMaxMass()) < 0.01) Pooh.fly_down_extra(dt);
        std::cout << globalHeight << std::endl;

        circle.move(0, -globalHeight*0.01);

        window.draw(circle);
        

        window.clear();
        window.draw(circle);
        window.display();
        }
    

    return 0;
}