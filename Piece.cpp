/******************************************************/
/* This is the implementation file of the class Piece */
/******************************************************/

#include "Piece.h"
#include <iostream>
#include <cstring>
using namespace std;

Piece::Piece(int xCoord, int yCoord, bool colour, char name) :
    xCoord(xCoord), yCoord(yCoord), isWhite (colour), isFirstMove(true),
    counter(0), name(name) {
}

Piece::~Piece() {
	// body intentionally empty
}

bool Piece::isPieceWhite() {
	return isWhite;      
}
char Piece::getPieceName() {
	return name;
}
void Piece::moveCounter() {
	counter++;         
}
int Piece::getMoveCounter() { 
	return counter;    
}
void Piece::setXYCoord(int newX, int newY) {
    xCoord = newX;
    yCoord = newY;
}

bool Piece::isValidMove(int destination[2], Piece* board[X_MAX][Y_MAX]) {
    
    bool valid = true;
    int destX = destination[0];
    int destY = destination[1];
    int xTranslation = destX - xCoord;
    int yTranslation = destY - yCoord;
    Piece* targetPiece = board[destX][destY];
    // Check if destination is within board boundaries
    if (destX < 0 || destX >= X_MAX)
    	valid = false;
    if (destY < 0 || destY >= Y_MAX)
    	valid = false;
    // Check if the trajectory is blocked 
    if (!isPathClear(xTranslation, yTranslation, targetPiece, board))
    	valid = false;
    // Check if the move is legal for each piece
    if (!isMoveLegal(xTranslation, yTranslation))             
    	valid = false;
   	return valid; // true if none of the above checked 
}

bool isPathClear(int xTranslation, int yTranslation, Piece* targetPiece, Piece* board[X_MAX][Y_MAX]) {

  bool valid = true;
  int xStep = 0, yStep = 0; // for checking direction
  int xCounter = 0, yCounter = 0; // for keeping track of squares
  Piece* nextSquare = NULL;
  // Check if piece at destination is own 
  if (targetPiece != NULL && (targetPiece->isPieceWhite() == isWhite))
    	valid = false;
  // Horizontal movement: xTranslation != 0; yTranslation == 0
  // Vertical movement: xTranslation == 0; yTranslation != 0
  // Diagonal movement: xTranslation != 0; yTranslation != 0
  // If white piece - translation is positive 
  // If black piece - translation is negative 
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
  // While not at destination, check if square on path is empty 
  // If empty, update xCounter by 1/-1 if horizontal movement OR
  // Update yCounter by 1/-1 if vertical  movement OR
  // Update both by 1/-1 if diagonal movement
  while (xTranslation != xCounter || yTranslation != yCounter) {
    nextSquare = board[xCoord + xCounter][yCoord + yCounter];
    if (nextSquare != NULL)
      valid = false; 
    xCounter += xStep;
    yCounter += yStep;
   }

}



