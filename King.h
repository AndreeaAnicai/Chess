/*****************************************************/ 
/*  
	Andreea Anicai - MSc Computing 2018
	This is the header file King.h
	This is the interface for the class King
*/
/*****************************************************/

#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
	// Inherits default constructor from Piece (x/y/colour/name)
    King(int xCoord, int yCoord, bool colour); 

    // Inherits default virtual deconstructor from Piece
    ~King();

    // Check if King can move to destination based on its rules
	// King moves 1 square only in each direction)
    bool isMoveLegal(int xTranslation, int yTranslation) override;
};

#endif // KING_H
