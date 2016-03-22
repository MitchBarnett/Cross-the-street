#include "Vehicle.h"
#include <iostream>
#include <ctime>





Vehicle::Vehicle(float speed, float xPos, float yPos, char type)
{
	fX = xPos;
	fY = yPos;
	fXSpeed = speed;

	switch (type){
	case 'c':
		fLength = 100.0f;
		vehicleShape.setPosition(sf::Vector2f(fX, fY));
		vehicleShape.setSize(sf::Vector2f(fLength, 46.0f));
		vehicleShape.setFillColor(sf::Color::Red);
		break; //optional
	case 's':
		fLength = 150.0f;
		vehicleShape.setPosition(sf::Vector2f(fX, fY));
		vehicleShape.setSize(sf::Vector2f(fLength, 46.0f));
		vehicleShape.setFillColor(sf::Color::Blue);
		break; //optional

		// you can have any number of case statements.
	default: //Optional
		std::cout << "not a valid type of vehicle, default car type set " << std::endl;
		fLength = 100.0f;
		vehicleShape.setPosition(sf::Vector2f(fX, fY));
		vehicleShape.setSize(sf::Vector2f(fLength, 46.0f));
		vehicleShape.setFillColor(sf::Color::Red);
		break; //optional
	}

}

void Vehicle::setSpeed(float speed)
{
	fXSpeed = speed;
}

void Vehicle::update(float elapsed)
{
	fX += fXSpeed * elapsed;
	vehicleShape.setPosition(sf::Vector2f(fX, fY + 2.0f));
}

void Vehicle::draw(sf::RenderWindow& window)
{
	window.draw(vehicleShape);
}
bool Vehicle::checkCollision(sf::FloatRect other)
{
	if (vehicleShape.getGlobalBounds().intersects(other))
	{
		return true;
	}else{
		return false;
	}
}