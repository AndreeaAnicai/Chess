/******************************************************/
/* This is the implementation file of the class Bishop */
/******************************************************/

#include "Bishop.h"
#include <iostream>
#include <cstdlib>

Bishop::Bishop(int xCoord, int yCoord, bool colour) : Piece(xCoord, yCoord, colour, 'B') {
}

Bishop::~Bishop() {

}
bool Bishop::isMoveLegal(int xTranslation, int yTranslation) {
	bool valid = true;
	if (xTranslation == 0 || yTranslation == 0) { //Not diagonal movement
		valid = false;
	}
	if (abs(xTranslation) != abs(yTranslation)) {
		valid = false;
	}
	return valid;
}

