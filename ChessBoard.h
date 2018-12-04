/*****************************************************/ 
/*  This is the header file ChessBoard.h
	This is the interface for the class ChessBoard
*/
/*****************************************************/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"
#include "Utilities.h"

class ChessBoard 
{
public:
	/* BOARD FUNCTIONALITY */

	// Creates 8x8 board initialised to nullptr 
	ChessBoard();
	// Destructor returns all dynamic memory used on the heap 
	~ChessBoard();
	// Sets up all the pieces on the board 
	void initialiseBoard();
	// Prints all the pieces on the board
	void printBoard();
	// Deletes and replaces all existing pieces with nullptr
	void resetBoard();

	/* CHECK USER INPUT AND SET COORDINATES */

	// Checks if user input is valid and if it is, sets the coordinates in an int array
	bool checkInputValid(const char* input, int coordinates[2]);
	// Check if square has null pointer or piece 
	bool isSquareEmpty(Piece*, const char*);

	/* CHECK AND SUBMIT MOVE */

	// Takes user input for source and destination and makes piece move 
	void submitMove(const char* source, const char* destination);


private:
	Piece* board[X_MAX][Y_MAX];
	int turn;
};

#endif //CHESSBOARD_H