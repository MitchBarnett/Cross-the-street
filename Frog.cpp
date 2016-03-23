#include "Frog.h"
#include <iostream>


Frog::Frog()
{
	iX = 0;
	iY = 0;
	iMoves = 0;
	iLivesLeft = 3;
	frogBox.setSize(sf::Vector2f(50.0f, 50.0f));
	frogBox.setFillColor(sf::Color::Green);
}

void Frog::movePosition(int iNewX, int iNewY)
{
	iX = iNewX;
	iY = iNewY;
	frogBox.setPosition(iX, iY);
}

void Frog::moveLeft()
{
	movePosition(iX - 50, iY);
}
void Frog::moveRight()
{
	movePosition(iX + 50, iY);
}
void Frog::moveUp()
{
	movePosition(iX , iY - 50);
}
void Frog::moveDown()
{
	movePosition(iX , iY + 50);
}

sf::Vector2i Frog::getposition(int type)
{
	sf::Vector2i position;
	switch (type){
	case 0:				// Current position
		position.x = iX;
		position.y = iY;
		return position;
		break;
	case 1:				// Moving left
		position.x = iX - 50;
		position.y = iY;
		return position;
		break;
	case 2:				// Moving right
		position.x = iX + 50;
		position.y = iY;
		return position;
		break;
	case 3:				// Moving up
		position.x = iX;
		position.y = iY -50;
		return position;
		break;
	case 4:				// Moving down
		position.x = iX;
		position.y = iY + 50;
		return position;
		break;
	}
}
bool Frog::onScreen(sf::Vector2u uWindow, int type)
{
	sf::Vector2i window (uWindow.x, uWindow.y);
	// loop throught each point
	for (int i = 0; i < frogBox.getPointCount(); i++)
	{
		sf::Vector2f globalPos(frogBox.getPosition());
		sf::Vector2f localPoint(frogBox.getPoint(i));
		sf::Vector2f globalPoint(globalPos.x + localPoint.x, globalPos.y + localPoint.y);

		if(type == 0) //stationary
		{
			if (globalPoint.x > window.x)		{ return false; } // too far left
			else if (globalPoint.y > window.y)	{ return false; } // too far down
			else if (globalPoint.x < 0)			{ return false; } // too far right
			else if (globalPoint.y < 0)			{ return false; } // too far up
		}

		if (type == 1) // left
		{
			if (globalPoint.x - 50 < 0)		{ return false; } // too far left
		}

		if (type == 2) // right
		{
			if (globalPoint.x + 50 > window.x)			{ return false; } // too far right

		}

		if (type == 3) //up
		{
			if (globalPoint.y - 50 < 0)			{ return false; } // too far up
		}

		if (type == 4) //down
		{
			if (globalPoint.y + 50 > window.y)	{ return false; } // too far down
		}

		
	}

	 return true;  // in the screen
}

void Frog::checkMovement(sf::Event& event, sf::RenderWindow& window)
{
	sf::Time cooldown = sf::seconds(0.25f);
	if (event.type == sf::Event::KeyPressed &&  movementCooldown.getElapsedTime() > cooldown)

	{
		if (event.key.code == sf::Keyboard::Left && onScreen(window.getSize(), 1))
		{
			moveLeft();
			movementCooldown.restart();
			iMoves++;
		}
		if (event.key.code == sf::Keyboard::Right && onScreen(window.getSize(), 2))
		{
			moveRight();
			movementCooldown.restart();
			iMoves++;
		}
		if (event.key.code == sf::Keyboard::Up && onScreen(window.getSize(), 3))
		{
			moveUp();
			movementCooldown.restart();
			iMoves++;
		}
		if (event.key.code == sf::Keyboard::Down && onScreen(window.getSize(), 4))
		{
			moveDown();
			movementCooldown.restart();
			iMoves++;
		}
	}
}

void Frog::update(sf::Event& event, sf::RenderWindow& window)
{
	checkMovement(event, window);
}