/*****************************************************/ 
/*  
    Andreea Anicai - MSc Computing 2018
    This is the header file Piece.h
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
    char getPieceInitial();
    // Return a char array with the piece name
    const char* getPieceName();
    // Return a char array with the piece colour 
    const char* getPieceColour();
    // Set isFirstMove to false after moving
    void updateFirstMove();
    // Returns the value of isFirstMove
    bool returnIsFirstMove();
    // Resets x and y coordinates for piece
    void setXYCoord(int newX, int newY);
    /* Function that checks if move is valid taking into account
    	- board spatial limits 
		- individual piece allowed movement - isMoveLegal()
		- whether there are blocking pieces - isDirectionClear()
    */ 
    bool isValidMove(int destination[2], Piece* board[X_MAX][Y_MAX]);
    /* 
     * Check if trajectory is blocked by any piece
     * Horizontal movement: xTranslation != 0; yTranslation == 0
     * Vertical movement: xTranslation == 0; yTranslation != 0
     * Diagonal movement: xTranslation != 0; yTranslation != 0
     * If white piece - translation is positive 
     * If black piece - translation is negative 
    */
    virtual bool isDirectionClear(int xTranslation, int yTranslation, Piece* targetPiece, Piece* board[X_MAX][Y_MAX]);
    /*
     * Check if the move is allowed by each piece's rules
     * SET AS PURE VIRTUAL FUNCTION
    */
    virtual bool isMoveLegal(int xTranslation, int yTranslation) = 0;

protected:
    int xCoord; 
    int yCoord; 
    bool isWhite;
    char name; 
    bool isFirstMove;

}; 

#endif //PIECE_H
