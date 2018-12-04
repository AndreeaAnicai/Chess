/******************************************************/
/* This is the implementation file of the class Queen */
/******************************************************/

#include "Pawn.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Pawn::Pawn(int xCoord, int yCoord, bool colour) : Piece(xCoord, yCoord, colour, 'P') {
	// Body intentionally empty
}

Pawn::~Pawn() {
	// Body intentionally empty
}

bool Pawn::isPathClear(int xTranslation, int yTranslation, Piece* targetPiece, Piece *board[X_MAX][Y_MAX]) {
  
	// SAME AS PIECE 
  	bool valid = true;
  	int xStep = 0, yStep = 0; // for checking direction
  	int xCounter = 0, yCounter = 0; // for keeping track of squares
  	Piece* nextSquare = NULL;

  	if (targetPiece != NULL && (targetPiece->isPieceWhite() == isWhite)) { // Same colour piece at dest
    	valid = false;
    }
  	// JUST FOR PAWN
  	if (targetPiece == NULL && abs(xTranslation) == abs(yTranslation) == 1) { // Diagonal move and no capturing piece
  		valid = false;
  	}
  	if (isFirstMove) { //Pawn can move 2 squares so check vertical
  		if (xTranslation > 0) 
    		xStep = 1;
  		else if (xTranslation < 0)
    		xStep = -1;
  		if (yTranslation > 0) 
    		yStep = 1;
 	 	else if (xTranslation < 0)
    		yStep = -1;
  		xCounter = xStep; 
  		yCounter = yStep; 

  		while (xTranslation != xCounter || yTranslation != yCounter) {
    		nextSquare = board[xCoord + xCounter][yCoord + yCounter];
    		if (nextSquare != NULL)
      		valid = false; 
    		xCounter += xStep;
    		yCounter += yStep;
   		}
  	}
}

bool Pawn::isMoveLegal(int xTranslation, int yTranslation) {
	bool valid = true;
    if (isFirstMove) {
    	if (!(abs(yTranslation) == 1 || abs(yTranslation) == 2))
    		valid = false;
    	if (yTranslation == 2 && xTranslation !=0 )// Advances 2 sqaures but has horizontal movement
    		valid = false;
    }
    else {
    	if (abs(yTranslation) != 1)
    		valid = false;
    }
    // No vertical movement or incorrect direction for piece colour
    if (yTranslation == 0 || (yTranslation < 0 && isWhite) || (yTranslation > 0 && !isWhite)) 
    	valid == false;
    if (abs(xTranslation) > 1) // 1 if capturing
    	valid == false;
    return valid;

}



