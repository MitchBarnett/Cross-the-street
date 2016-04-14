#include "movable.h"

sf::Vector2f Movable::getPosition()
{
	return box.getPosition();
}
bool  Movable::onScreen(sf::RenderWindow& window)
{
	sf::Vector2f windowSize(window.getSize().x, window.getSize().y);
	sf::Vector2f globalPos(getPosition());
	sf::Vector2f localPoint;
	sf::Vector2f globalPoint;

	for (int i = 0; i < box.getPointCount(); i++)
	{
		sf::Vector2f localPoint(box.getPoint(i));
		sf::Vector2f globalPoint(globalPos.x + localPoint.x, globalPos.y + localPoint.y);

		if (globalPoint.x > windowSize.x)		{ return false; } // too far left
		else if (globalPoint.y > windowSize.y)	{ return false; } // too far down
		else if (globalPoint.x < 0)			{ return false; } // too far right
		else if (globalPoint.y < 0)			{ return false; } // too far up
	}
	return true;
}
bool  Movable::onScreen(sf::RenderWindow& window, sf::Vector2f transformation)
{
	sf::Vector2f windowSize(window.getSize().x, window.getSize().y);
	sf::Vector2f globalPos(getPosition() + transformation);
	sf::Vector2f localPoint;
	sf::Vector2f globalPoint;

	for (int i = 0; i < box.getPointCount(); i++)
	{
		sf::Vector2f localPoint(box.getPoint(i));
		sf::Vector2f globalPoint(globalPos.x + localPoint.x, globalPos.y + localPoint.y);

		if (globalPoint.x > windowSize.x)		{ return false; } // too far left
		else if (globalPoint.y > windowSize.y)	{ return false; } // too far down
		else if (globalPoint.x < 0)			{ return false; } // too far right
		else if (globalPoint.y < 0)			{ return false; } // too far up
	}
	return true;
}
bool  Movable::checkCollision(sf::FloatRect other)
{
	if (getBounds().intersects(other))
	{
		return true;
	}
	else{
		return false;
	}
}
void  Movable::setPosition(sf::Vector2f transformation)
{
	box.setPosition(transformation);
}
void  Movable::update(float elapsed)
{

}