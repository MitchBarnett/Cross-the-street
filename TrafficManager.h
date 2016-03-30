#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

class TrafficManager
{
public:

	TrafficManager(); //Constructor
	void loadTextures();
	void update(float elapsed);
	void draw(sf::RenderWindow& window);
	bool checkCollision(sf::FloatRect other);
private:
	std::vector<sf::Texture*> fastVehicleTextures;
	std::vector<sf::Texture*> mediumVehicleTextures;
	std::vector<sf::Texture*> slowVehicleTextures;
	std::vector<TrafficLane> lanes;


	sf::Texture fastTexture1;
	sf::Texture fastTexture2;
	sf::Texture fastTexture3;
	sf::Texture fastTexture4;
	sf::Texture fastTexture5;
	sf::Texture fastTexture6;
	sf::Texture fastTexture7;
	sf::Texture fastTexture8;
	sf::Texture fastTexture9;
	sf::Texture fastTexture10;

	sf::Texture mediumTexture1;
	sf::Texture mediumTexture2;
	sf::Texture mediumTexture3;
	sf::Texture mediumTexture4;
	sf::Texture mediumTexture5;
	sf::Texture mediumTexture6;
	sf::Texture mediumTexture7;
	sf::Texture mediumTexture8;
	sf::Texture mediumTexture9;

	sf::Texture slowTexture1;
	sf::Texture slowTexture2;
	sf::Texture slowTexture3;
};

#endif