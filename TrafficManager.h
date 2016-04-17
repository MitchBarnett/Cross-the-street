#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

class TrafficManager
{
public:
	// Constructor
	TrafficManager();

	// Destructor
	~TrafficManager();

	// Loads the .png of vehicles into 3 arrays of sf::Texture objects depending on their speed
	void loadTextures();

	void unloadTextures();

	// updates all traffic objects position
	void update(float elapsed);

	// Draws all traffic objects to the passed window
	void draw(sf::RenderWindow& window);

	// Returns true if any traffic object collides with the passed FloatRect
	bool checkCollision(sf::FloatRect other);

private:
	// A vector containing pointers to the textures
	std::vector<sf::Texture*> aptexFastVehicleTextures;
	std::vector<sf::Texture*> aptexMediumVehicleTextures;
	std::vector<sf::Texture*> aptexSlowVehicleTextures;

	// A vector to hold the traffic lanes
	std::vector<TrafficLane> lanes;

};

#endif