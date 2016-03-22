#include "CarSpawner.h"
#include "Car.h"
#include <iostream>

CarSpawner::CarSpawner()
{
	//Car car;
	sf::Clock clock;

	float fRightTopSpeed	= getLaneSpeed();
	float fRightMiddleSpeed = getLaneSpeed();
	float fRightBottomSpeed = getLaneSpeed();

	float fLeftTopSpeed		= getLaneSpeed();
	float fLeftMiddleSpeed	= getLaneSpeed();
	float fLeftBottomSpeed	= getLaneSpeed();
}
void CarSpawner::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < cars.size(); i++){
		window.draw(cars[i].carBox);
	}
}
void CarSpawner::update()
{
	for (int i = 0; i < cars.size(); i++){
		cars[i].update();
	}
	if (clock.getElapsedTime().asSeconds() > nextSpawn){
//		cars.push_back(Car());
		clock.restart();
		nextSpawn = getNextSpawn();
	}
}
float CarSpawner::getNextSpawn()
{
	return rand() % 5 + 1;
}

float CarSpawner::getLaneSpeed()
{
	return rand() % 100 + 50;
}