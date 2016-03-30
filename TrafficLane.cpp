#include "TrafficLane.h"
#include "Car.h"
#include "Vehicle.h"
#include <iostream>
#include <vector>


TrafficLane::TrafficLane()
{
	laneHeight = 50.0f;
	laneXStart = -100.0f;
	direction = 'f';
	laneType = 'c';
	sf::Clock timeSinceSpawn;
	sf::Clock laneTime;
	std::cout << "constructed" << std::endl;

	iLaneSpeed = getLaneSpeed(direction);
}

TrafficLane::TrafficLane(float xPos, float yPos, char direction, char type, std::vector<sf::Texture*> textures)
{
	carTextures = textures;
	laneHeight = yPos;
	laneXStart = xPos;
	direction = direction;
	laneType = type;
	iLaneSpeed = getLaneSpeed(direction);
}

void TrafficLane::draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < carsInLane.size(); i++){
		(carsInLane[i]).draw(window);
	}

}
void TrafficLane::update(float elapsed)
{
	for (unsigned int i = 0; i < carsInLane.size(); i++){
		carsInLane[i].update(elapsed);
	}

	if (laneTime.getElapsedTime().asSeconds() < 0.2){
		timeSinceSpawn = spawnTimer.getElapsedTime().asSeconds() * 60;
	}else{
		timeSinceSpawn = spawnTimer.getElapsedTime().asSeconds();
	}
	if (timeSinceSpawn > nextSpawn ){
		carsInLane.push_back(Vehicle(iLaneSpeed, laneXStart, laneHeight, laneType, carTextures));
		spawnTimer.restart();
		nextSpawn = getNextSpawn();
	}

	if (carsInLane.size() > 15)
	{
		carsInLane.erase(carsInLane.begin());
	}
}

float TrafficLane::getNextSpawn()
{
	int iTempLaneSpeed;
	if (iLaneSpeed < 0)
	{
		iTempLaneSpeed = -iLaneSpeed;
	}else{
		iTempLaneSpeed = iLaneSpeed;
	}
	
	float fMinTime; 	// Time for a car to pass the spawn area
	float fMaxTime;		// Time for a 5 cars to pass the spawn area
	if (laneType == 's'){
		fMinTime = 150.0f / iTempLaneSpeed;		// Time for a car to pass the spawn area
		fMaxTime = 150.0f / iTempLaneSpeed * 3;
	}
	else{
		fMinTime = 100.0f / iTempLaneSpeed;		// Time for a car to pass the spawn area
		fMaxTime = 100.0f / iTempLaneSpeed * 6;
	}
	return (fMinTime + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (fMaxTime - fMinTime)))); //Return a float between the min and max times
}

int TrafficLane::getLaneSpeed(char direction)
{
	switch (laneType){
	case 'c':
		if (direction == 'f' || direction == 'F')
		{
			return rand() % 100 + 80;
		}
		else{
			return -(rand() % 100 + 80);
		}
		break; //optional
	case 's':
		if (direction == 'f' || direction == 'F')
		{
			return rand() % 40 + 40;
		}
		else{
			return -(rand() % 40 + 40);
		}
		break; //optional

		// you can have any number of case statements.
	default: //Optional
		std::cout << "not a valid type of vehicle, default car speed set " << std::endl;
		if (direction == 'f' || direction == 'F')
		{
			return rand() % 100 + 50;
		}
		else{
			return -(rand() % 100 + 50);
		}
		break; //optional
	}

}
bool TrafficLane::checkCollision(sf::FloatRect other)
{
	for (unsigned int i = 0; i < carsInLane.size(); i++){
		if (carsInLane[i].checkCollision(other))
		{
			return true;
		}
	}
	return false;
}