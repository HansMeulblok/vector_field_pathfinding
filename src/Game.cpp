#include "Game.h"

// private funtions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "gaming", sf::Style::Titlebar | sf::Style::Close);
}

// Constructors / destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}
Game::~Game()
{
	delete this->window;
}

// Accessors


// functions 

const bool Game::gameRunning() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
    // event polling
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case::sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{

    //- clear old frame
    //- render objects
    //- display frame in window

    this->window->clear(sf::Color(239, 213, 129, 255));

    // Draw game

    this->window->display();
}