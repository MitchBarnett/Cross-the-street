#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Movable.h"

class Player : public Movable
{
public:
	int iLivesLeft;
	int iMoves;
	sf::Clock movementCooldown;
	Player(); //Constructor
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void checkMovement(sf::Event& event, sf::RenderWindow& window);
	void update(sf::Event& event, sf::RenderWindow& window);
	void loseLife();
};

#endif