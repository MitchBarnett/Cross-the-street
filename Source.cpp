#include <SFML/Graphics.hpp>
#include "Frog.h"
#include "Car.h"
#include "Background.h"
#include "CarSpawner.h"
#include "TrafficLane.h"
#include "TrafficManager.h"
#include "TextItem.h"
#include "Entity.h"
#include "Movable.h"
#include "Player.h"
#include <string>
#include <sstream>
#include <iostream>

int calcScore(float time, int moves, int lives)
{
	int timeScore = static_cast<int>(time);
	return (timeScore + moves - lives * 5) + 1;

}


int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 680), "My window");
	window.setFramerateLimit(60);

	srand(time(NULL));
	CarSpawner carManager;
	Player player;

	TrafficManager trafficManager;
	Background background;
	int livesLeft = 3;
	TextItem lives("Lives: ", player.iLivesLeft, sf::Vector2f(0,650)); // Creates lives UI item
	TextItem moves("Moves: ", player.iMoves, sf::Vector2f(700, 650)); // Creates lives UI item
	TextItem time("Time: ", 0.0f, sf::Vector2f(300, 650));
	
	player.setPosition(sf::Vector2f(350, 0));
	sf::Clock gameClock;
	sf::Clock frameClock;
	float elapsed = 0.01;
	int score = calcScore(gameClock.getElapsedTime().asSeconds(), player.iMoves, player.iLivesLeft);
	TextItem gameScore("Score:  ", score, sf::Vector2f(350, 320));

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

		lives.update("Lives: ", player.iLivesLeft);
		time.update("Time: ", gameClock.getElapsedTime().asSeconds());
		moves.update("Moves: ", player.iMoves);

		

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		background.draw(window);
		player.draw(window);
		trafficManager.draw(window);
		if (trafficManager.checkCollision(player.getBounds()))
		{
			player.iLivesLeft--;
			player.setPosition(sf::Vector2f(350, 0));
		}
		lives.draw(window);
		time.draw(window);
		moves.draw(window);
		if (player.iLivesLeft == 0)
		{
			window.clear(sf::Color::Black);
			TextItem gameOver("Game Over", sf::Vector2f(250, 300), 50);
			gameOver.draw(window);
		}
		else if(player.getBounds().intersects(background.bottom.getGlobalBounds())){
			window.clear(sf::Color::Black);
			TextItem gameWin("Congratulations", sf::Vector2f(230, 250), 50);
			gameWin.draw(window);
			gameScore.draw(window);
		}
		else{
			score = calcScore(gameClock.getElapsedTime().asSeconds(), player.iMoves, player.iLivesLeft);
			gameScore.update("Score: ", score);
		}


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