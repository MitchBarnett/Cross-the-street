#include "Background.h"
#include <iostream>


Background::Background()
{
	bottom.setSize(sf::Vector2f(900.0f, 50.0f));
	centralRes.setSize(sf::Vector2f(900.0f, 50.0f));
	top.setSize(sf::Vector2f(900.0f, 50.0f));
	topRoad.setSize(sf::Vector2f(900.0f, 250.0f));
	bottomRoad.setSize(sf::Vector2f(900.0f, 250.0f));

	sf::Color grey(150, 150, 150);
	bottom.setFillColor(grey);
	centralRes.setFillColor(grey);
	top.setFillColor(grey);

	centralRes.setPosition(sf::Vector2f(0.0f, 300.0f));
	bottom.setPosition(sf::Vector2f(0.0f, 600.0f));
	topRoad.setPosition(sf::Vector2f(0, 50));
	bottomRoad.setPosition(sf::Vector2f(0, 350));


	if (!roadTexture.loadFromFile("images/background/Road.png"))
	{
		topRoad.setFillColor(sf::Color::Black);
		bottomRoad.setFillColor(sf::Color::Black);
	}

	if (!pavementTextureTop.loadFromFile("images/background/Pavement_top.png"))
	{
	}
	if (!pavementTextureBottom.loadFromFile("images/background/Pavement_bottom.png"))
	{
	}
	if (!centralResTexture.loadFromFile("images/background/CenteralRes.png"))
	{
	}
	top.setTexture(&pavementTextureTop);
	centralRes.setTexture(&centralResTexture);
	bottom.setTexture(&pavementTextureBottom);
	topRoad.setTexture(&roadTexture);
	bottomRoad.setTexture(&roadTexture);

}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(bottom);
	window.draw(centralRes);
	window.draw(top);
	window.draw(topRoad);
	window.draw(bottomRoad);
}