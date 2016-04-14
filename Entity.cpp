#include "Entity.h"
#include <iostream>
sf::FloatRect Entity::getBounds()
{
	return box.getGlobalBounds();
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(box);
}