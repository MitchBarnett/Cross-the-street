#include "TrafficLane.h"
#include "TrafficManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
TrafficManager::TrafficManager()
{
	loadTextures();
	lanes.push_back(TrafficLane(-100, 50, 'f', 's', slowVehicleTextures));
	lanes.push_back(TrafficLane(-100, 100, 'f', 's', slowVehicleTextures));
	lanes.push_back(TrafficLane(-100, 150, 'f', 'c', mediumVehicleTextures));
	lanes.push_back(TrafficLane(-100, 200, 'f', 'c', mediumVehicleTextures));
	lanes.push_back(TrafficLane(-100, 250, 'f', 'c', fastVehicleTextures));
	lanes.push_back(TrafficLane(900, 350, 'r', 'c', fastVehicleTextures));
	lanes.push_back(TrafficLane(900, 400, 'r', 'c', mediumVehicleTextures));
	lanes.push_back(TrafficLane(900, 450, 'r', 'c', mediumVehicleTextures));
	lanes.push_back(TrafficLane(900, 500, 'r', 's', slowVehicleTextures));
	lanes.push_back(TrafficLane(900, 550, 'r', 's', slowVehicleTextures));
}

void TrafficManager::loadTextures()
{
	if (!fastTexture1.loadFromFile("images/vehicles/fast/AudiBlue.png"))
	{
		std::cout << "AudiBlue.png missing" << std::endl;
	}
	if (!fastTexture2.loadFromFile("images/vehicles/fast/AudiGreen.png"))
	{
		std::cout << "AudiGreen.png missing" << std::endl;
	}
	if (!fastTexture3.loadFromFile("images/vehicles/fast/AudiPurple.png"))
	{
		std::cout << "AudiPurple.png missing" << std::endl;
	}
	if (!fastTexture4.loadFromFile("images/vehicles/fast/AudiRed.png"))
	{
		std::cout << "AudiRed.png missing" << std::endl;
	}
	if (!fastTexture5.loadFromFile("images/vehicles/fast/AudiYellow.png"))
	{
		std::cout << "AudiYellow.png missing" << std::endl;
	}
	if (!fastTexture6.loadFromFile("images/vehicles/fast/ViperBlackOrange.png"))
	{
		std::cout << "ViperBlackOrange.png missing" << std::endl;
	}
	if (!fastTexture7.loadFromFile("images/vehicles/fast/ViperBlackRed.png"))
	{
		std::cout << "ViperBlackRed.png missing" << std::endl;
	}
	if (!fastTexture8.loadFromFile("images/vehicles/fast/ViperBlackWhite.png"))
	{
		std::cout << "ViperBlackWhite.png missing" << std::endl;
	}
	if (!fastTexture9.loadFromFile("images/vehicles/fast/ViperWhiteBlack.png"))
	{
		std::cout << "WhiteBlack.png missing" << std::endl;
	}
	if (!fastTexture10.loadFromFile("images/vehicles/fast/Police.png"))
	{
		std::cout << "Police.png missing" << std::endl;
	}
	fastVehicleTextures.push_back(&fastTexture1);
	fastVehicleTextures.push_back(&fastTexture2);
	fastVehicleTextures.push_back(&fastTexture3);
	fastVehicleTextures.push_back(&fastTexture4);
	fastVehicleTextures.push_back(&fastTexture5);
	fastVehicleTextures.push_back(&fastTexture6);
	fastVehicleTextures.push_back(&fastTexture7);
	fastVehicleTextures.push_back(&fastTexture8);
	fastVehicleTextures.push_back(&fastTexture9);
	fastVehicleTextures.push_back(&fastTexture10);

	if (!mediumTexture1.loadFromFile("images/vehicles/medium/CarBlue.png"))
	{
		std::cout << "carBlue.png missing" << std::endl;
	}
	if (!mediumTexture2.loadFromFile("images/vehicles/medium/CarGreen.png"))
	{
		std::cout << "carGreen.png missing" << std::endl;
	}
	if (!mediumTexture3.loadFromFile("images/vehicles/medium/CarOrange.png"))
	{
		std::cout << "carOrange.png missing" << std::endl;
	}
	if (!mediumTexture4.loadFromFile("images/vehicles/medium/CarRed.png"))
	{
		std::cout << "carRed.png missing" << std::endl;
	}
	if (!mediumTexture5.loadFromFile("images/vehicles/medium/CarYellow.png"))
	{
		std::cout << "carYellow.png missing" << std::endl;
	}

	if (!mediumTexture6.loadFromFile("images/vehicles/medium/PickupBlue.png"))
	{
		std::cout << "PickupBlue.png missing" << std::endl;
	}
	if (!mediumTexture7.loadFromFile("images/vehicles/medium/PickupGreen.png"))
	{
		std::cout << "PickupGreen.png missing" << std::endl;
	}
	if (!mediumTexture8.loadFromFile("images/vehicles/medium/PickupRed.png"))
	{
		std::cout << "PickupRed.png missing" << std::endl;
	}
	if (!mediumTexture9.loadFromFile("images/vehicles/medium/Taxi.png"))
	{
		std::cout << "Taxi.png missing" << std::endl;
	}
	mediumVehicleTextures.push_back(&mediumTexture1);
	mediumVehicleTextures.push_back(&mediumTexture2);
	mediumVehicleTextures.push_back(&mediumTexture3);
	mediumVehicleTextures.push_back(&mediumTexture4);
	mediumVehicleTextures.push_back(&mediumTexture5);
	mediumVehicleTextures.push_back(&mediumTexture6);
	mediumVehicleTextures.push_back(&mediumTexture7);
	mediumVehicleTextures.push_back(&mediumTexture8);
	mediumVehicleTextures.push_back(&mediumTexture9);

	if (!slowTexture1.loadFromFile("images/vehicles/slow/Ambulance.png"))
	{
		std::cout << "Ambulance.png missing" << std::endl;
	}

	if (!slowTexture2.loadFromFile("images/vehicles/slow/Truck.png"))
	{
		std::cout << "Truck.png missing" << std::endl;
	}
	if (!slowTexture3.loadFromFile("images/vehicles/slow/Van.png"))
	{
		std::cout << "Van.png missing" << std::endl;
	}
	slowVehicleTextures.push_back(&slowTexture1);
	slowVehicleTextures.push_back(&slowTexture2);
	slowVehicleTextures.push_back(&slowTexture3);
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