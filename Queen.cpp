/******************************************************/
/* This is the implementation file of the class Queen */
/******************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

Queen::Queen(int xCoord, int yCoord, bool colour) : Piece(int xCoord, int yCoord, bool colour, 'Q') {
	// Body intentionally empty
}

Queen::~Queen() {
	// Body intentionally empty
}

bool Queen::isMoveLegal(int xTranslation, int yTranslation) {
	bool valid = true;
	if (xTranslation == 0 || yTranslation == 0) { // Horizontal or vertical
		valid = false;
	}
	if (abs(xTranslation) != abs(yTranslation)) { // Diagonal
		valid = false;
	}
	if (xTranslation == 0 && yTranslation == 0) { // Piece not moving
		valid = false;
	}
	return valid;
}