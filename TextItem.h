#ifndef TEXTITEM_H
#define TEXTITEM_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>


class TextItem
{
public:
	sf::Text text;
	int value;
	std::ostringstream textStream;
	sf::Font font;
	TextItem(std::string textString, int value); //Constructor
	void setSpeed(float speed);
	void update(std::string textString, int value);
	void draw(sf::RenderWindow& window);
};

#endif
