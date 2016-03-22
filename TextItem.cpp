#include "TextItem.h"
#include <sstream>
#include <iostream>

TextItem::TextItem(std::string textString, int value)
{
	
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "fail" << std::endl;
	}

	text.setFont(font); // font is a sf::Font

	// set the string to display

	textStream << textString << value;
	std::string newString(textStream.str());
	text.setString(newString);

	// set the character size
	text.setCharacterSize(22); // in pixels, not points!

	// set the color
	text.setColor(sf::Color::Black);
}

void TextItem::update(std::string textString, int value)
{
	textStream << textString << value;
	std::string newString(textStream.str());
	text.setString(newString);
	textStream.str("");
}
void TextItem::draw(sf::RenderWindow& window)
{
	window.draw(text);
}