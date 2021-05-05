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
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Pooh flight model");

    const float dt = 0.1; // s
    FlyingBear Pooh(1, 10); //(mass, Height)
    sf::Texture texture;
    texture.loadFromFile("img/pooh.png");
    Pooh.sprite.setTexture(texture);
    Pooh.sprite.setScale(0.2, 0.2);
    Pooh.sprite.setPosition(100,450);
    sf::Vector2f position = Pooh.sprite.getPosition();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Pooh.fly_up(dt);
		while (Pooh.sprite.getPosition().y > Pooh.getHollowHeight()*10){
			//std::cout << "h = " << abs(Pooh.sprite.getPosition().y - 450)/34<< "\n";
	        Pooh.sprite.move(0, -10); //toDo change to y = velocity 
	        window.setFramerateLimit(10);
        	window.clear();
        	window.draw(Pooh.sprite);
        	window.display();
	    }
        if (abs(Pooh.getHollowHeight() - Pooh.getHeight()) < 0.1) Pooh.eat(dt);
        if (abs(Pooh.getMass() - Pooh.getMaxMass()) < 0.01) {
            Pooh.fly_down_extra(dt);
    	    while (abs(Pooh.getMass() - Pooh.getMaxMass()) < 0.01){
    			//std::cout << "h = " << Pooh.sprite.getPosition().y << "\n";
    	        Pooh.sprite.move(0, 10);
    	        window.setFramerateLimit(10);
            	window.clear();
            	window.draw(Pooh.sprite);
            	window.display();
    	    }
        }
    }
    return 0;
}