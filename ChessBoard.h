/*****************************************************/ 
/*  This is the header file ChessBoard.h
	This is the interface for the class ChessBoard
*/
/*****************************************************/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H>

#include <ostream>
#include <string>
#include "Piece.h"
using namespace std:

class ChessBoard 
{
public:

	// Creates 8x8 board 
	ChessBoard();

	// Destructor - returns all dynamic memory used on the heap 
	~ChessBoard();

	// Get the current board 
	static ChessBoard* getBoard();

	// Function that checks if vertical trajectory is clear; returns 1 if true
	bool checkVertical( fromSquare,  toSquare) const;

	// Function that checks if horizontal trajectory is clear; returns 1 if true
	bool checkHorizontal( fromSquare,  toSquare) const;

	// Function that checks if diagonal trajectory is clear; 
	bool checkDiagonal( fromSquare,  toSquare) const;

	// Check if sqaure if occupied by piece or nullptr
	// Returns 1/true if not null, 0/false otherwise
	bool isSquareOccupied() const;

	// Set the x and y coordinates for Piece to supplied numbers
	void setPieceCoord (Piece& piece, int x, int y);

	// Move piece once move is validated, and update coordinates on board
	void submitMove ( fromSquare, toSquare) const;

	// Display interface of board with all pieces
	void printBoard(ostream& outStream) const;

private:
	static ChessBoard* thisChessBoard;
	static const int MAX_DIMENSION = 8;
	Piece* board[MAX_DIMENSION][MAX_DIMENSION];
	

}; //ChessBoard class

#endif //CHESSBOARD_H