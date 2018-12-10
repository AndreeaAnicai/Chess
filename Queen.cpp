/******************************************************/
/* 
	Andreea Anicai - MSc Computing 2018
	This is the implementation file of the class Queen 
*/
/******************************************************/

#include "Queen.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Queen::Queen(int xCoord, int yCoord, bool colour) : Piece(xCoord, yCoord, colour, 'Q') {
	// Body intentionally empty
}

Queen::~Queen() {
	// Body intentionally empty
}

bool Queen::isMoveLegal(int xTranslation, int yTranslation) {
	if (xTranslation != 0 && yTranslation != 0 && (abs(xTranslation) != abs(yTranslation))) { // Diagonal
		return false;
	}
	if (xTranslation == 0 && yTranslation == 0) { // Piece not moving
		return false;
	}
	return true;
}