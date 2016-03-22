#include "Background.h"
#include <iostream>


Background::Background()
{
	bottom.setSize(sf::Vector2f(800.0f, 50.0f));
	centeralRes.setSize(sf::Vector2f(800.0f, 50.0f));
	top.setSize(sf::Vector2f(800.0f, 50.0f));

	sf::Color grey(150, 150, 150);
	bottom.setFillColor(grey);
	centeralRes.setFillColor(grey);
	top.setFillColor(grey);

	centeralRes.setPosition(sf::Vector2f(0.0f, 300.0f));
	bottom.setPosition(sf::Vector2f(0.0f, 600.0f));

}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(bottom);
	window.draw(centeralRes);
	window.draw(top);
}