/******************************************************/
/* This is the implementation file of the class Piece */
/******************************************************/

#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;

	Piece::Piece (bool isWhite) : isWhite(isWhite) {
    
    if(isWhite)
    	colour = "W";
    else
        colour = "B";

	}
	Piece::Piece (const Piece& object) {
		// Body intentionally empty	
	}
	Piece::~Piece () {
		// Body intentionally empty
	}
	bool Piece::isWhite () const {
		return isWhite;
	}
	int Piece::getXCoord () const {
		return xCoord;
	}
	int Piece::getYCoord () const {
		return yCoord;
	}
	string Piece::getColour() const {
		return colour;
	}






