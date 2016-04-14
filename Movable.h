#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Movable : public Entity
{
public:
	sf::Vector2f getPosition();
	bool onScreen(sf::RenderWindow&);
	bool onScreen(sf::RenderWindow&, sf::Vector2f transformation);
	bool checkCollision(sf::FloatRect other);
	void setPosition(sf::Vector2f transformation);
	void update(float elapsed);
private:

};


#endif