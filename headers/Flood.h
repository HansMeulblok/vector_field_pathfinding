#pragma once
#include "SFML/Graphics.hpp"
#include "CONSTANTS.h"
#include "utilitiyFunctions.h"
#include "gridItem.h"
#include "gridUtility.h"
#include "FloodAlgorithm.h"

void Flood(sf::RenderWindow& window, bool& isSolved, bool& escapePressed);

