#include "Player.h"
#include <iostream>

Player::Player()
{
	iMoves = 0;
	iLivesLeft = 3;
	box.setSize(sf::Vector2f(50, 50));

	if (!playerTexture.loadFromFile("images/frog.png"))
	{
		box.setFillColor(sf::Color::Green);
	}

	box.setTexture(&playerTexture);

	box.setOrigin(box.getSize().x / 2, box.getSize().y / 2);
}

void Player::moveLeft()
{
	setPosition(getPosition()+ sf::Vector2f(-50,0));
	box.setRotation(90);
}
void Player::moveRight()
{
	setPosition(getPosition() + sf::Vector2f(50, 0));
	box.setRotation(270);
}
void Player::moveUp()
{
	setPosition(getPosition() + sf::Vector2f(0, -50));
	box.setRotation(180);
}
void Player::moveDown()
{
	setPosition(getPosition() + sf::Vector2f(0, 50));
	box.setRotation(0);
}



void Player::checkMovement(sf::Event& event, sf::RenderWindow& window)
{
	sf::Time cooldown = sf::seconds(0.25f);
	if (event.type == sf::Event::KeyPressed &&  movementCooldown.getElapsedTime() > cooldown)

	{
		if (event.key.code == sf::Keyboard::Left && onScreen(window, sf::Vector2f(-50, 0)))
		{
			moveLeft();
			movementCooldown.restart();
			iMoves++;
		}
		else if (event.key.code == sf::Keyboard::Right && onScreen(window, sf::Vector2f(50, 0)))
		{
			moveRight();
			movementCooldown.restart();
			iMoves++;
		}
		else if (event.key.code == sf::Keyboard::Up && onScreen(window, sf::Vector2f(0, -50)))
		{
			moveUp();
			movementCooldown.restart();
			iMoves++;
		}
		else if (event.key.code == sf::Keyboard::Down && onScreen(window, sf::Vector2f(0, 50)))
		{
			moveDown();
			movementCooldown.restart();
			iMoves++;
		}
	}
}

void Player::update(sf::Event& event, sf::RenderWindow& window)
{
	checkMovement(event, window);
}