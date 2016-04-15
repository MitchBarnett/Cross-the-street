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

// Calculates the score based on passed values
int calcScore(float time, int moves, int lives)
{
	int timeScore = static_cast<int>(time);
	return (timeScore + moves - lives * 5) + 1;

}


int main()
{
	srand(time(NULL));				// Seeds the random number generator

	sf::RenderWindow window(sf::VideoMode(800, 680), "My window"); // create the window
	Player player;					// Creates a player
	TrafficManager trafficManager;	// Manages all the traffic
	Background background;			// Sets up the background

	int score = 1000;		// Tracks the players score
	float elapsed = 0.01;	// Stores the value of the frame time

	TextItem lives("Lives: ", player.iLivesLeft, sf::Vector2f(0,650));	// Creates Lives UI item
	TextItem moves("Moves: ", player.iMoves, sf::Vector2f(675, 650));	// Creates Moves UI item
	TextItem time("Time: ", 0.0f, sf::Vector2f(300, 650));				// Creates Time UI item
	TextItem gameScore("Score:  ", score, sf::Vector2f(350, 320));
	
	player.setPosition(sf::Vector2f(375, 25));	//sets the initial player vlaue

	sf::Clock gameClock;	// A clock to track how long the game has been running
	sf::Clock frameClock;	// Tracks how much time the last frame took
	
	

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
		frameClock.restart();			// Restarts frame clock for new frame
		player.update(event, window);	// Check if the user has requested the player to move
		trafficManager.update(elapsed);	// Updates traffic all trafic objects

		// Checks for a collision between the player and traffic objects
		if (trafficManager.checkCollision(player.getBounds()))
		{
			player.iLivesLeft--;
			player.setPosition(sf::Vector2f(375, 25));
		}

		// Updates UI elements
		lives.update("Lives: ", player.iLivesLeft);
		time.update("Time: ", gameClock.getElapsedTime().asSeconds());
		moves.update("Moves: ", player.iMoves);


		// clear the window with black color for start of drawing a new frame
		window.clear(sf::Color::Black);

		// Draw game componenets to the screen
		background.draw(window);
		player.draw(window);
		trafficManager.draw(window);

		// Draw UI elements to the screen
		lives.draw(window);
		time.draw(window);
		moves.draw(window);
		
		// Draw a the game over screen if game is lost
		if (player.iLivesLeft <= 0)
		{
			window.clear(sf::Color::Black);
			TextItem gameOver("Game Over", sf::Vector2f(250, 300), 50);
			gameOver.draw(window);
		}

		// Draw the game win screen is game is won
		else if(player.getBounds().intersects(background.bottom.getGlobalBounds())){
			window.clear(sf::Color::Black);
			TextItem gameWin("Congratulations", sf::Vector2f(230, 250), 50);
			gameWin.draw(window);
			gameScore.draw(window);
		}

		// Update the players score
		else{
			score = calcScore(gameClock.getElapsedTime().asSeconds(), player.iMoves, player.iLivesLeft);
			gameScore.update("Score: ", score);
		}


		// Display the current frame
		window.display();

		// update elapsed value
		elapsed = frameClock.getElapsedTime().asSeconds();

		// Speed up game time for inital population of map
		if (gameClock.getElapsedTime().asSeconds() < 0.1)
		{
			elapsed = elapsed * 60;
		}
	}

	return 0;
}