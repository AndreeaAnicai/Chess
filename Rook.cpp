/******************************************************/
/* This is the implementation file of the class Rook */
/******************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

Rook::Rook(int xCoord, int yCoord, bool colour) : Piece (xCoord, yCoord, colour, 'R') {
	// Body intentionally empty
}

Rook::~Rook() {
	// Body intentionally empty
}

bool Rook::isMoveLegal(int xTranslation, int yTranslation) {
	bool valid = true;
	if (xTranslation == 0 || yTranslation == 0) {
		valid = false;
	}
	if (xTranslation == 0 && yTranslation == 0) { // Piece not moving
		valid = false;
	}
	return valid;
}