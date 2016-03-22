#ifndef CARSPAWNER_H
#define CARSPAWNER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Car.h"


class CarSpawner
{
public:
	CarSpawner(); //Constructor

	float fRightTopSpeed;
	float fRightMiddleSpeed;
	float fRightBottomSpeed;

	float fLeftTopSpeed;
	float fLeftMiddleSpeed;
	float fLeftBottomSpeed;

	float nextSpawn;
	std::vector<Car> cars;
	sf::Clock clock;
	
	void draw(sf::RenderWindow& window);
	void update();
	
	float getNextSpawn();
	float getLaneSpeed();
	
};

#endif