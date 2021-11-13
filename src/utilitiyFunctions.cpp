#include "utilitiyFunctions.h"
#include <iostream>

void grabEvents(sf::RenderWindow& window, bool& escapePressed) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.key.code == sf::Keyboard::Escape) escapePressed = true;
    }
}

void grabMouseClickEvents(sf::RenderWindow& window, bool& escapePressed, int& step, std::vector<std::vector<gridItem>>& gridsArray, sf::Vector2i& homeCoords, sf::Vector2i& targetCoords) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Check for left click.
        if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && step == 0) {
            // Set home
            sf::Vector2i position = sf::Mouse::getPosition(window);
            sf::Vector2i gridCoords = mouseCoordinate(position);

            // if within grid
            if (gridCoords.x > horizontalGridCount || gridCoords.x < 0 || gridCoords.y > verticalGridCount || gridCoords.y < 0) continue;
  
            gridsArray[gridCoords.y][gridCoords.x].squareShape.setFillColor(sf::Color::Green);
            gridsArray[gridCoords.y][gridCoords.x].setHome();
            homeCoords = sf::Vector2i{ gridCoords.y, gridCoords.x };        
     
            step++;
        }
        else if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right && step == 1)
        {
            // set target
            sf::Vector2i position = sf::Mouse::getPosition(window);
            sf::Vector2i gridCoords = mouseCoordinate(position);

            // if within grid
            if (gridCoords.x > horizontalGridCount || gridCoords.x < 0 || gridCoords.y > verticalGridCount || gridCoords.y < 0) continue;

            gridsArray[gridCoords.y][gridCoords.x].squareShape.setFillColor(sf::Color::Blue);
            gridsArray[gridCoords.y][gridCoords.x].setTarget();
            targetCoords = sf::Vector2i{ gridCoords.y, gridCoords.x };
            step++;

        }
        else if (event.key.code == sf::Keyboard::Escape) 
        {
            escapePressed = true;
        }
    }

}

void grabMouseDragEvents(sf::RenderWindow& window, bool& escapePressed, int& step, std::vector<std::vector<gridItem>>& gridsArray) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Request for closing the window
        if (event.type == sf::Event::Closed) {
            escapePressed = true;
        }
        // Check for left click.
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i position = sf::Mouse::getPosition(window);
                sf::Vector2i gridCoords = mouseCoordinate(position);

                // The code below is a bit painful to look at but its a concise way of making sure the mouse doesnt try to click anywhere out of bounds!
                if (position.x > ROUNDED_X_SIZE - 5 || position.x < 5 || position.y > ROUNDED_Y_SIZE - 5 || position.y < 5) continue;

                gridsArray[gridCoords.y][gridCoords.x].squareShape.setFillColor(sf::Color::Red);
                gridsArray[gridCoords.y][gridCoords.x].setWall();
                window.clear();
                drawGrid(gridsArray, window);
                window.display();
            }
            step++;
        }
        else if (event.key.code == sf::Keyboard::Escape) 
        {
            escapePressed = true;
        }
    }
}

sf::Vector2i mouseCoordinate(sf::Vector2i mousePos) {
    int x = mousePos.x / gridSize;
    int y = mousePos.y / gridSize;
    return sf::Vector2i{ x,y };
}

gridItem* getGridAt(sf::Vector2i location, std::vector<std::vector<gridItem>>& gridsArray) {
    return &(gridsArray.at(location.x).at(location.y));
}

