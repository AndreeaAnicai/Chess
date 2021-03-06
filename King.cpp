/******************************************************/
/* 
	Andreea Anicai - MSc Computing 2018
	This is the implementation file of the class King 
*/
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
    if (abs(xTranslation) > 1) // Only 1 square horizontally
    	return false; 
    if (abs(yTranslation) > 1) // Only 1 square vertically
		return false; 
    if (xTranslation == 0 && yTranslation == 0) // If the position does not change at all
    	return false; 
    return true;

}
