#ifndef BUS_H
#define BUS_H

#include <SFML/Graphics.hpp>


class Bus
{
public:
	float fX;
	float fY;
	float fXSpeed;
	sf::RectangleShape carBox;
	Bus(float speed, float xPos, float yPos); //Constructor
	void setSpeed(float speed);
	void update();
	void draw(sf::RenderWindow& window);
};

#endif
