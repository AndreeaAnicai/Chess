/*****************************************************/ 
/*  This is the header file Piece.h
	This is the interface for the class Piece
	This is intended to be used as a base class to
	derive classes for all chess pieces 
	ABSTRACT CLASS
*/
/*****************************************************/

#ifndef PIECE_H
#define PIECE_H

#include "Utilities.h"

class Piece 
{
public:
	// Default contstructor
    Piece(int xCoord, int yCoord, bool colour, char name);
    // Default deconstructor
    virtual ~Piece();
    // Check colour of piece, returns 1 if white and 0 is black
    bool isPieceWhite();
    // Returns letter that represents piece name
    char getPieceName();
    // Set isFirstMove to false after moving
    void updateFirstMove();
    // Resets x and y coordinates for piece
    void setXYCoord(int newX, int newY);
    /* 
    	Function that checks if move is valid taking into account
    	- board spatial limits 
		- individual piece allowed movement - isMoveLegal()
		- whether there are blocking pieces - isPathClear()
    */ 
    bool isValidMove(int destination[2], Piece* board[X_MAX][Y_MAX]);
    // Check if trajectory is blocked by any piece
    virtual bool isPathClear(int xTranslation, int yTranslation, Piece* targetPiece, Piece* board[X_MAX][Y_MAX]);
    // Check if the move is allowed by each piece's rules
    // SET AS PURE VIRTUAL FUNCTION
    virtual bool isMoveLegal(int xTranslation, int yTranslation) = 0;

protected:
    int xCoord; 
    int yCoord; 
    bool isWhite;
    bool isFirstMove;
    char name; 

}; // Piece class

#endif //PIECE_H
