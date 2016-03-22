#include "Bus.h"
#include <iostream>
#include <ctime>

Bus::Bus(float speed, float xPos, float yPos)
{
	fX = xPos;
	fY = yPos;
	fXSpeed = speed;
	carBox.setPosition(sf::Vector2f(fX, fY));
	carBox.setSize(sf::Vector2f(150.0f, 46.0f));
	carBox.setFillColor(sf::Color::Blue);
}
void Bus::setSpeed(float speed)
{
	fXSpeed = speed;
}

void Bus::update()
{
	fX += fXSpeed * 0.01667;
	carBox.setPosition(sf::Vector2f(fX, fY + 2.0f));
}

void Bus::draw(sf::RenderWindow& window)
{
	window.draw(carBox);
}