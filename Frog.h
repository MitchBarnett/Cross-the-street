#ifndef FROG_H
#define FROG_H

#include <SFML/Graphics.hpp>


class Frog
{
public:
	int iX;
	int iY;
	Frog(); //Constructor
	void movePosition(int iNewX, int iNewY);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	sf::Vector2i getposition(int type);
	bool onScreen(sf::Vector2u window, int type);
	sf::RectangleShape frogBox;
	void checkMovement(sf::Event& event, sf::Clock&, sf::RenderWindow& window);
};

#endif