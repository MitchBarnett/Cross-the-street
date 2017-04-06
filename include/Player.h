// Author: Mitch Barnett
// Created: April 2016

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Movable.h"

// Creates a player object that can be controlled by a user
class Player : public Movable
{
public:
	// Constructor
	Player();

	//resets to default values;
	void reset();

	// Returns the lives the player has remaining
	int getLivesLeft();	

	// Returns the number of moves the player has took
	int getMovesTaken();

	// Decrements the number of lives the player has left
	void loseLife();

	// Checks for user input and makes the appropiate move if possible
	void checkMovement(sf::Event& event, sf::RenderWindow& window);	

	// Updates the players position
	void update(sf::Event& event, sf::RenderWindow& window);
	
private:
	int m_iLivesLeft;	// The number of lives the player has left
	int m_iMoves;		// The number of moves the player has made
	sf::Clock moveCooldownClock; // Keeps track of the cooldown of when the player cannot move
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	sf::Texture texPlayerTexture; // Holds the texture for the player
};

#endif
