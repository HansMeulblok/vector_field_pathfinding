#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>


// Class that acts as the game egnine / wrapper class.

class Game
{
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	// Private functions
	void initVariables();
	void initWindow();

public:

	// Constructors / destructors
	Game();
	virtual ~Game();


	// Accessors
	const bool gameRunning() const;

	// Functions
	void pollEvents();
	void update();
	void render();

};