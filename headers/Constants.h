#pragma once
#include "SFML/Graphics.hpp"

	// Grid item sizes
	const float gridSize = 25; 
	const float borderThickness = 1; 
	const float adjustedGridSize = gridSize - borderThickness;

	const int horizontalGridCount = 50;
	const int verticalGridCount = 50;

	const int ROUNDED_X_SIZE = horizontalGridCount * gridSize;

	const int ROUNDED_Y_SIZE = verticalGridCount * gridSize;
