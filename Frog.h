#ifndef FROG_H
#define FROG_H

#include <SFML/Graphics.hpp>


class Frog
{
public:
	int iX;
	int iY;
	int iLivesLeft;
	int iMoves;
	sf::Clock movementCooldown;
	Frog(); //Constructor
	void setPosition(int iNewX, int iNewY);
	void movePosition(int iMoveX, int iMoveY);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	sf::Vector2i getposition(int type);
	bool onScreen(sf::Vector2u window, int type);
	sf::RectangleShape frogBox;
	void checkMovement(sf::Event& event, sf::RenderWindow& window);
	void update(sf::Event& event, sf::RenderWindow& window);
	sf::FloatRect getBounds();
	sf::Texture playerTexture;
};

#endif