#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "utilitiyFunctions.h"
#include "Flood.h"

bool isSolved = false;
bool escapePressed = false;


int main() {
    sf::RenderWindow window(sf::VideoMode(ROUNDED_X_SIZE, ROUNDED_Y_SIZE), "Flood Algorithm");

    while (window.isOpen())
    {

        Flood(window, isSolved, escapePressed);

        if (escapePressed)
        {
            window.close();
        }
    }

}