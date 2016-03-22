#include "Car.h"
#include <iostream>
#include <ctime>





Car::Car(float speed, float xPos, float yPos)
{
	fX = xPos;
	fY = yPos;
	fXSpeed = speed;
	carBox.setPosition(sf::Vector2f(fX, fY));
	carBox.setSize(sf::Vector2f(100.0f, 46.0f));
	carBox.setFillColor(sf::Color::Red);
}
void Car::setSpeed(float speed)
{
	fXSpeed = speed;
}

void Car::update()
{
	fX += fXSpeed * 0.01667;
	carBox.setPosition(sf::Vector2f(fX, fY + 2.0f));
}

void Car::draw(sf::RenderWindow& window)
{
	window.draw(carBox);
}