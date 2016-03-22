#ifndef CAR_H
#define CAR_H

#include <SFML/Graphics.hpp>


class Car
{
public:
	float fX;
	float fY;
	float fXSpeed;
	sf::RectangleShape carBox;
	Car(float speed, float xPos, float yPos); //Constructor
	void setSpeed(float speed);
	void update();
	void draw(sf::RenderWindow& window);
};

#endif