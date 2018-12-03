/*****************************************************/ 
/*  This is the header file Kinght.h
	This is the interface for the class Knight
*/
/*****************************************************/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
	// Inherits default constructor from Piece (x/y/colour/name)
    Knight(int xCoord, int yCoord, bool colour); 

    // Inherits default virtual deconstructor from Piece
    ~Knight();

    // Override virtual function here because Knight can skip over pieces
    bool pathIsClear(int xTranslation, int yTranslation, ChessPiece* targetPiece, ChessPiece *board[X_MAX][Y_MAX]);
    
	// Check if Knight can move to destination based on its rules
	// Knight moves eithertwo squares sideways and then one square up/down  or 
	// moves two squares up/down and then one square sideways
	// abs(xTranslation) = 1/2, abs(yTranslation) = 1/2
    bool displacementOK(int xTranslation, int yTranslation);
};

#endif
