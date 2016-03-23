#include <SFML/Graphics.hpp>
#include "Frog.h"
#include "Car.h"
#include "Background.h"
#include "CarSpawner.h"
#include "TrafficLane.h"
#include "TrafficManager.h"
#include "TextItem.h"
#include <string>
#include <sstream>
#include <iostream>



int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 680), "My window");
	window.setFramerateLimit(60);

	srand(time(NULL));
	CarSpawner carManager;
	Frog player;
	/*TrafficLane lane1(-100, 50);
	TrafficLane lane2(-100, 100);
	TrafficLane lane3(-100, 150);
	TrafficLane lane4(-100, 200);
	TrafficLane lane5(-100, 250);*/
	TrafficManager trafficManager;
	Background background;
	int livesLeft = 3;
	TextItem lives("Lives: ", livesLeft, sf::Vector2f(0,650)); // Creates lives UI item
	TextItem moves("Moves: ", player.iMoves, sf::Vector2f(700, 650)); // Creates lives UI item
	TextItem time("Time: ", 0.0f, sf::Vector2f(300, 650));

	player.movePosition(350, 0);
	sf::Clock gameClock;
	sf::Clock frameClock;
	float elapsed = 0.01;


	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		frameClock.restart();
		//Check if the user has requested the player to move
		player.update(event, window);
		trafficManager.update(elapsed);
		lives.update("Lives: ", livesLeft);
		moves.update("Moves: ", player.iMoves);
		time.update("Time: ", gameClock.getElapsedTime().asSeconds());
		/*lane1.update();
		lane2.update();
		lane3.update();
		lane4.update();
		lane5.update();*/


		

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		background.draw(window);
		window.draw(player.frogBox);
		trafficManager.draw(window);
		if (trafficManager.checkCollision(player.frogBox.getGlobalBounds()))
		{
			std::cout << "-1 life" << std::endl;
			//livesLeft --;
			//player.movePosition(350, 0);
		}
		lives.draw(window);
		moves.draw(window);
		time.draw(window);
		if (livesLeft == 0)
		{
			window.clear(sf::Color::Black);
		}
		/*lane1.draw(window);
		lane2.draw(window);
		lane3.draw(window);
		lane4.draw(window);
		lane5.draw(window);*/


		// end the current frame
		window.display();
		elapsed = frameClock.getElapsedTime().asSeconds();
		if (gameClock.getElapsedTime().asSeconds() < 0.1)
		{
			elapsed = elapsed * 60;
		}
	}

	return 0;
}