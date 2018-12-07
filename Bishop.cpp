/******************************************************/
/* This is the implementation file of the class Bishop */
/******************************************************/

#include "Bishop.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Bishop::Bishop(int xCoord, int yCoord, bool colour) : Piece(xCoord, yCoord, colour, 'B') {
	// Body intentionally empty
}

Bishop::~Bishop() {
	// Body intentionally empty
}
bool Bishop::isMoveLegal(int xTranslation, int yTranslation) {
	
	if (xTranslation == 0 || yTranslation == 0) { //Not diagonal movement
		return false;
	}
	if (abs(xTranslation) != abs(yTranslation)) {
		return false;
	}
	return true;
}

