/******************************************************/
/* This is the implementation file of the class Piece */
/******************************************************/

#include "Piece.h"
#include <iostream>
#include <cstring>
using namespace std;

Piece::Piece(int xCoord, int yCoord, bool colour, char name) :
    xCoord(xCoord), yCoord(yCoord), isWhite(colour), name(name), isFirstMove(true) {
}

Piece::~Piece() {
	// body intentionally empty
}

bool Piece::isPieceWhite() {
	return isWhite;      
}
char Piece::getPieceInitial() {
	return name;
}
const char* Piece::getPieceName() {
  switch(name) {
    case 'B': return "Bishop"; break;
    case 'K': return "King"; break;
    case 'N': return "Knight"; break;
    case 'P': return "Pawn"; break;
    case 'Q': return "Queen"; break;
    case 'R': return "Rook"; break;
    default: return "Piece name incorrect";
    }
}
const char* Piece::getPieceColour() {
  if (isWhite)
    return "White";
  else 
    return "Black";
}
void Piece::updateFirstMove() {
  isFirstMove = false;
}
bool Piece::returnIsFirstMove() {
  return isFirstMove;
}
void Piece::setXYCoord(int newX, int newY) {
  xCoord = newX;
  yCoord = newY;
}

bool Piece::isValidMove(int destination[2], Piece* board[X_MAX][Y_MAX]) {
    
    int destX = destination[0];
    int destY = destination[1];
    int xTranslation = destX - xCoord;
    int yTranslation = destY - yCoord;
    Piece* targetPiece = board[destX][destY];
    // Check if destination is within board boundaries
    if (destX < 0 || destX >= X_MAX)
      return false;
    if (destY < 0 || destY >= Y_MAX)
      return false;
    // Check if the trajectory is blocked 
    if (!isDirectionClear(xTranslation, yTranslation, targetPiece, board))
      return false;
    // Check if the move is legal for each piece
    if (!isMoveLegal(xTranslation, yTranslation))             
      return false;
  return true; 
}
bool Piece::isDirectionClear(int xTranslation, int yTranslation, Piece* targetPiece, Piece* board[X_MAX][Y_MAX]) {

  int xStep = 0, yStep = 0; // for checking direction
  int xCounter = 0, yCounter = 0; // for keeping track of squares
  Piece* nextSquare = NULL;
  // Check if piece at destination is own 
  if (targetPiece != NULL && (targetPiece->isPieceWhite() == isWhite))
    	return false;
  // Horizontal movement: xTranslation != 0; yTranslation == 0
  // Vertical movement: xTranslation == 0; yTranslation != 0
  // Diagonal movement: xTranslation != 0; yTranslation != 0
  // If white piece - translation is positive 
  // If black piece - translation is negative 
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
  // While not at destination, check if square on path is empty 
  // If empty, update xCounter by 1/-1 if horizontal movement OR
  // Update yCounter by 1/-1 if vertical  movement OR
  // Update both by 1/-1 if diagonal movement
  while (xTranslation != xCounter || yTranslation != yCounter) {
    nextSquare = board[xCoord + xCounter][yCoord + yCounter];
    if (nextSquare != NULL)
      return false; 
    xCounter += xStep;
    yCounter += yStep;
   }
   return true;
}



