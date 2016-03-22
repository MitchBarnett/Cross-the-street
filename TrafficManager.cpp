#include "TrafficLane.h"
#include "TrafficManager.h"
#include <SFML/Graphics.hpp>

TrafficManager::TrafficManager()
{
	for (int i = 0; i < 5; i++)
	{
		if (i < 2){
			lanes[i].laneType = 's';
		}
		lanes[i].laneXStart = -100;
		lanes[i].laneHeight = i * 50 + 50;
		lanes[i].iLaneSpeed = lanes[i].getLaneSpeed('f');
	}
	
	for (int i = 5; i < 10; i++)
	{
		if (i > 7){
			lanes[i].laneType = 's';
		}
		lanes[i].laneXStart = 900;
		lanes[i].laneHeight = i * 50 + 100;
		lanes[i].iLaneSpeed = lanes[i].getLaneSpeed('R');
	}
}

void TrafficManager::update(float elapsed)
{
	for (int i = 0; i < 10; i++){
		lanes[i].update(elapsed);
	}
}

void TrafficManager::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 10; i++){
		lanes[i].draw(window);
	}
}

bool TrafficManager::checkCollision(sf::FloatRect other)
{
	for (int i = 0; i < 10; i++){
		if (lanes[i].checkCollision(other))
		{
			return true;
		}
	}
	return false;
}