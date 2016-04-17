#include "TrafficLane.h"
#include "TrafficManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
TrafficManager::TrafficManager()
{
	loadTextures();
	lanes.push_back(TrafficLane(-150, 50, 'f', 's', aptexSlowVehicleTextures));
	lanes.push_back(TrafficLane(-150, 100, 'f', 's', aptexSlowVehicleTextures));
	lanes.push_back(TrafficLane(-100, 150, 'f', 'c', aptexMediumVehicleTextures));
	lanes.push_back(TrafficLane(-100, 200, 'f', 'c', aptexMediumVehicleTextures));
	lanes.push_back(TrafficLane(-100, 250, 'f', 'c', aptexFastVehicleTextures));
	lanes.push_back(TrafficLane(900, 350, 'r', 'c', aptexFastVehicleTextures));
	lanes.push_back(TrafficLane(900, 400, 'r', 'c', aptexMediumVehicleTextures));
	lanes.push_back(TrafficLane(900, 450, 'r', 'c', aptexMediumVehicleTextures));
	lanes.push_back(TrafficLane(950, 500, 'r', 's', aptexSlowVehicleTextures));
	lanes.push_back(TrafficLane(950, 550, 'r', 's', aptexSlowVehicleTextures));
}

TrafficManager::~TrafficManager()
{
	unloadTextures();
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

void TrafficManager::loadTextures()
{
	// Set values for size of the arrays
	const int kiFastFiles = 10;
	const int kiMediumFiles = 9;
	const int kiSlowFiles = 3;

	// List of textures files for fast vehicles 
	std::string asFastFiles[kiFastFiles] =
	{
		"images/vehicles/fast/AudiBlue.png",
		"images/vehicles/fast/AudiGreen.png",
		"images/vehicles/fast/AudiPurple.png",
		"images/vehicles/fast/AudiRed.png",
		"images/vehicles/fast/AudiYellow.png",
		"images/vehicles/fast/ViperBlackOrange.png",
		"images/vehicles/fast/ViperBlackRed.png",
		"images/vehicles/fast/ViperBlackWhite.png",
		"images/vehicles/fast/ViperWhiteBlack.png",
		"images/vehicles/fast/Police.png"
	};
	// List of texture files for medium vehicles 	
	std::string asMediumFiles[kiMediumFiles] =
	{
		"images/vehicles/medium/CarBlue.png",
		"images/vehicles/medium/CarGreen.png",
		"images/vehicles/medium/CarOrange.png",
		"images/vehicles/medium/CarRed.png",
		"images/vehicles/medium/CarYellow.png",
		"images/vehicles/medium/PickupBlue.png",
		"images/vehicles/medium/PickupGreen.png",
		"images/vehicles/medium/PickupRed.png",
		"images/vehicles/medium/Taxi.png"
	};
	// List of texture files for slow vehicles 	
	std::string asSlowFiles[kiSlowFiles] =
	{
		"images/vehicles/slow/Ambulance.png",
		"images/vehicles/slow/Truck.png",
		"images/vehicles/slow/Van.png"
	};

	
	for (int i = 0; i < kiFastFiles; i++)
	{
		aptexFastVehicleTextures.push_back(new sf::Texture);
		aptexFastVehicleTextures[i]->loadFromFile(asFastFiles[i]);
	}

	for (int i = 0; i < kiMediumFiles; i++)
	{
		aptexMediumVehicleTextures.push_back(new sf::Texture);
		aptexMediumVehicleTextures[i]->loadFromFile(asMediumFiles[i]);
	}

	for (int i = 0; i < kiSlowFiles; i++)
	{
		aptexSlowVehicleTextures.push_back(new sf::Texture);
		aptexSlowVehicleTextures[i]->loadFromFile(asSlowFiles[i]);
	}

}

void TrafficManager::unloadTextures()
{
	for (int i = 0; i < aptexFastVehicleTextures.size(); i++)
	{
		delete aptexFastVehicleTextures[i];
		aptexFastVehicleTextures[i] = nullptr;
	}

	for (int i = 0; i < aptexMediumVehicleTextures.size(); i++)
	{
		delete aptexMediumVehicleTextures[i];
		aptexMediumVehicleTextures[i] = nullptr;
	}

	for (int i = 0; i < aptexFastVehicleTextures.size(); i++)
	{
		delete aptexSlowVehicleTextures[i];
		aptexSlowVehicleTextures[i] = nullptr;
	}
}