/*****************************************************/ 
/*  This is the header file Rook.h
	This is the interface for the class Rook
*/
/*****************************************************/

#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook: public Piece {
public:
	// Inherits default constructor from Piece (x/y/colour/name)
	Rook(int xCoord, int yCoord, bool colour);

	// Inherits default virtual deconstructor from Piece
	~Rook();

	// Check if Rook can move to destination based on its rules
	// Rook moves only horizontally or vertically
	// abs(xTranslation) == 0 || abs(yTranslation) == 0
	bool isMoveLegal(int xTranslation, int yTranslation) override;

}; 

#endif // ROOK_H