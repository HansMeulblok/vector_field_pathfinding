#include "Flood.h"
#include <iostream>

void Flood(sf::RenderWindow& window, bool& isSolved, bool& escapePressed) {
	// Initialise the vector of <gridItems> which is defined in gridItem.h and implemented in gridItem.cpp.
	// The grid is drawn by the information contained by each object in this 2d vector array.
	std::vector<std::vector<gridItem>> gridsArray(verticalGridCount, std::vector<gridItem>(horizontalGridCount));
	sf::Vector2i sourceCoords, targetCoords;
	for (int row = 0; row < verticalGridCount; row++) {
		for (int col = 0; col < horizontalGridCount; col++) {
			gridsArray.at(row).at(col).setLocation(sf::Vector2i{ row, col });
		}
	}
	// Check which click the user is on. Eg: step 0-> set home point, step 1-> set target, step 2-> set walls.
	int setupStep = 0;


	while (!(escapePressed || isSolved)) {

		switch (setupStep) {
		case 0:
		case 1:
			grabMouseClickEvents(window, escapePressed, setupStep, gridsArray, sourceCoords, targetCoords);
			break;
		case 2:
			grabMouseDragEvents(window, escapePressed, setupStep, gridsArray);
			break;
		case 3:
			grabEvents(window, escapePressed);
			FloodAlgorithm(gridsArray, window, sourceCoords, targetCoords, escapePressed);
			setupStep++;
			break;
		default:
			grabEvents(window, escapePressed);
			break;
		}

		window.clear();
		drawGrid(gridsArray, window);
		window.display();

	}
}
