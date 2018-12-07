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

bool Pawn::isDirectionClear(int xTranslation, int yTranslation, Piece* targetPiece, Piece *board[X_MAX][Y_MAX]) {
	// SAME AS PIECE 
  int xStep = 0, yStep = 0; // for checking direction
  int xCounter = 0, yCounter = 0; // for keeping track of squares
  Piece* nextSquare = NULL;

  if (targetPiece != NULL && (targetPiece->isPieceWhite() == isWhite)) { // Same colour piece at dest
    return false;
  }
  // JUST FOR PAWN
  if (targetPiece == NULL && abs(xTranslation) == 1 && abs(yTranslation) == 1) { // Diagonal move and no capturing piece
  	return false;
  }

  if (isFirstMove) { //Pawn can move 2 squares so check vertical
  	if (xTranslation > 0) 
    		xStep = 1;
  	else if (xTranslation < 0)
    		xStep = -1;
    else; 
  	
    if (yTranslation > 0) 
    		yStep = 1;
 	 	else if (yTranslation < 0)
    		yStep = -1;
    else;
  	xCounter = xStep; 
  	yCounter = yStep; 

  	while (xTranslation != xCounter || yTranslation != yCounter) {
    	nextSquare = board[xCoord + xCounter][yCoord + yCounter];
    	if (nextSquare != NULL)
      	return false; 
    	xCounter += xStep;
    	yCounter += yStep;
   	}
  }
  return true;
}

bool Pawn::isMoveLegal(int xTranslation, int yTranslation) {
    if (isFirstMove) {
    	if ((abs(yTranslation) != 1 && abs(yTranslation) != 2))
    		return false;
    	if (yTranslation == 2 && xTranslation !=0 )// Advances 2 sqaures but has horizontal movement
    		return false;
    }
    else {
    	if (abs(yTranslation) != 1)
    		return false;
    }
    // No vertical movement or incorrect direction for piece colour
    if (yTranslation == 0 || (yTranslation < 0 && isWhite) || (yTranslation > 0 && !isWhite)) 
    	return false;
    if (abs(xTranslation) > 1) // 1 if capturing
    	return false;
    return true;

}



