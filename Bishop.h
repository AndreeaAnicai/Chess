/*****************************************************/ 
/*  
	Andreea Anicai - MSc Computing 2018
	This is the header file Bishop.h
	This is the interface for the class Bishop
*/
/*****************************************************/

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:
	// Inherits default constructor from Piece (x/y/colour/name)
	Bishop(int xCoord, int yCoord, bool colour);

	// Inherits default virtual deconstructor from Piece
	~Bishop();

	// Check if Bishop can move to destination based on its rules
	// Bishop moves any number of square on diagonal (abs(x) == abs(y))
	bool isMoveLegal(int xTranslation, int yTranslation) override;
}; 

#endif // BISHOP_H