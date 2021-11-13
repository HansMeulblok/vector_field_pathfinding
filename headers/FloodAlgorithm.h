#pragma once
#include "SFML/Graphics.hpp"
#include "gridItem.h"
#include <iostream>
#include <queue>
#include "utilitiyFunctions.h"
#include <algorithm>

void FloodAlgorithm(std::vector<std::vector<gridItem>>& 
gridItems, sf::RenderWindow& window, sf::Vector2i& source, sf::Vector2i& target, bool& escapePressed);