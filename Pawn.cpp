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
	
  int xStep = 0, yStep = 0; // for checking direction
  int xCounter = 0, yCounter = 0; // for keeping track of squares
  Piece* nextSquare = NULL;

  if (targetPiece != NULL && (targetPiece->isPieceWhite() == isWhite)) // Same colour piece capture
    return false;
  if (targetPiece == NULL && abs(xTranslation) == 1 && abs(yTranslation) == 1) // No diagonal if not capturing
    return false;
  if (targetPiece != NULL && (abs(xTranslation) != 1)) // Only vertical if target is empty
    return false;

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
    if ((xTranslation != 0 && abs(xTranslation) != 1))  
      return false; 
    if ((abs(yTranslation) != 1 && abs(yTranslation) != 2))  // can move 1 or 2 squares
      return false;
  }
  else {
    if ((xTranslation != 0 && abs(xTranslation) != 1))  
      return false;
    if ((abs(yTranslation) != 1))  // can only move 1 square 
      return false;
  }
  if ((yTranslation < 0) && isWhite) // white pawns go up 
    return false;
  if ((yTranslation > 0) && !isWhite) // black pawans go down
    return false;

  return true;
  
}



