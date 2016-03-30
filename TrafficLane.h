#ifndef TrafficLane_H
#define TrafficLane_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Vehicle.h"


class TrafficLane
{
public:

	
	float laneHeight;
	float laneXStart;
	char direction;
	char laneType;
	int iLaneSpeed;
	float nextSpawn;
	float timeSinceSpawn;

	std::vector<Vehicle> carsInLane;
	sf::Clock spawnTimer;
	sf::Clock laneTime;
	std::vector<sf::Texture*> carTextures;

	void draw(sf::RenderWindow& window);
	void update(float elapsed);

	float getNextSpawn();
	int getLaneSpeed(char direction);
	TrafficLane(); //Default Constructor
	TrafficLane(float xPos, float yPos, char direction, char type, std::vector<sf::Texture*> textures); //Overloaded Constructor

	bool checkCollision(sf::FloatRect other);

private:
};

#endif