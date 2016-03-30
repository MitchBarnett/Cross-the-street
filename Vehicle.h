#ifndef VEHICLE_H
#define VEHICLE_H

#include <SFML/Graphics.hpp>


class Vehicle
{
public:
	float fX;
	float fY;
	float fXSpeed;
	float fLength;
	sf::RectangleShape vehicleShape;
	sf::Texture *carTexture;
	std::vector<sf::Texture*> carTextures;
	Vehicle(float speed, float xPos, float yPos, char type, std::vector<sf::Texture*> textures); //Constructor
	void setSpeed(float speed);
	void update(float elapsed);
	void draw(sf::RenderWindow& window);
	bool checkCollision(sf::FloatRect other);
};

#endif