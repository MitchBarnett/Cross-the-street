#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::RectangleShape box;
	sf::Vector2f position;
	sf::FloatRect getBounds();
	void draw(sf::RenderWindow&);
};

#endif