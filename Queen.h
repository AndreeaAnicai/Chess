/*****************************************************/ 
/*  
	Andreea Anicai - MSc Computing 2018
	This is the header file Queen.h
	This is the interface for the class Queen
*/
/*****************************************************/

#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece  {
public: 
	// Inherits default constructor from Piece (x/y/colour/name)
	Queen(int xCoord, int yCoord, bool colour); 

	// Inherits default virtual deconstructor from Piece
	~Queen();

	/*
	 * Check if Queen can move to destination based on its rules
	 * Queen can move diagonally, horizontally, and vertically 
	 * Diagonal - abs(xTranslation) == abs(yTranslation) 
	 * Horizontal + vertical - abs(xTranslation) == 0 || abs(yTranslation) == 0
	*/
	bool isMoveLegal(int xTranslation, int yTranslation) override;
};

#endif //QUEEN_H