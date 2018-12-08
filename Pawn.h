/*****************************************************/ 
/*  This is the header file Pawn.h
	This is the interface for the class Pawn
*/
/*****************************************************/

#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
	// Inherits default constructor from Piece (x/y/colour/name)
	Pawn(int xCoord, int yCoord, bool colour); 

	// Inherits default virtual deconstructor from Piece
	~Pawn();

	// Override virtual function here because Pawn can move two ways
    bool isDirectionClear(int xTranslation, int yTranslation, Piece* targetPiece, Piece *board[X_MAX][Y_MAX]) override;

	// Check if Pawn can move to destination based on its rules
	// Advance 1/2 squares when not capturing
	// Diagonally 1 square when capturing 
	bool isMoveLegal(int xTranslation, int yTranslation) override;

};
#endif // PAWN_H