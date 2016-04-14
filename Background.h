#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>


class Background
{
public:
	Background(); //Constructor

	sf::Texture roadTexture;
	sf::Texture pavementTextureTop;
	sf::Texture centralResTexture;
	sf::Texture pavementTextureBottom;

	sf::RectangleShape topRoad;
	sf::RectangleShape bottomRoad;
	sf::RectangleShape bottom;
	sf::RectangleShape centralRes;
	sf::RectangleShape top;

	void draw(sf::RenderWindow& window);

};

#endif