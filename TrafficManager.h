#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

class TrafficManager
{
public:

	TrafficManager(); //Constructor
	void update(float elapsed);
	void draw(sf::RenderWindow& window);
	bool checkCollision(sf::FloatRect other);

private:
	TrafficLane lanes[10];
};

#endif