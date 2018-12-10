/******************************************************/
/* 
	Andreea Anicai - MSc Computing 2018
	This is the implementation file of the class Rook 
*/
/******************************************************/

#include "Rook.h"
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
	if (xTranslation != 0 && yTranslation != 0) {
		return false;
	}
	if (xTranslation == 0 && yTranslation == 0) { // Piece not moving
		return false;
	}
	return true;
}