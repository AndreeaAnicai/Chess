/******************************************************/
/* This is the implementation file of the class King */
/******************************************************/

#include "King.h"
#include <cstdlib>
using namespace std;

King::King(int xCoord, int yCoord, bool colour) : Piece(xCoord, yCoord, colour, 'K') {
	// Body intentionally empty
}

King::~King() {
	// Body intentionally empty
}

bool King::isMoveLegal(int xTranslation, int yTranslation) {
    if (abs(xTranslation) > 1)
    	return false; // Only 1 step allowed horizontally
    if (abs(yTranslation) > 1)
		return false; // Only 1 step allowed vertically
    if (xTranslation == 0 && yTranslation == 0)
    	return false; // If the position does not change at all
    return true;
}
