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
	/********************** BOARD FUNCTIONALITY ************************/

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

	/*************** CHECK USER INPUT AND SET COORDINATES *************/

	// Checks if user input is valid and if it is, sets the coordinates in an int array
	bool checkInputValid(const char* input, int coordinates[2]);
	// Check if square has null pointer or piece 
	bool isSquareEmpty(Piece*, const char*);
	// Check if it's the current player's turn
	bool isTurnCorrect(bool isWhite);

	/*************** FOR PRINTING THE PIECE NAME / COLOUR ************/

	const char* printPieceName(Piece* piece);
	const char* printPieceColour(Piece* piece);

	/********************* CHECK AND SUBMIT MOVE **********************/

	// Makes the move aftering checking for attacking piece, uses tryMove
	void makeMove(int source[2], int destination[2], Piece* playerPiece);
	// Attempts the move; if in check after making the move, reverse with undoMove
	void tryMove(int source[2], int destination[2], Piece* playerPiece);
	// Undo's the move if move leads to check
	void undoMove(int source[2], int destination[2], Piece* playerPiece);
	// Get the coordinates of the player's king 
	void getKingCoord (bool playerColour, int kingCoord[2]);
	/* Check if move attempted puts the player whose turn it is in check
	   - gets own king coordinates
	   - checks all non-null pieces that are not player's own
	   - if any of them has a valid move to king, player is in check
	*/
	bool isInCheck (bool playerColour);
	/* Takes user input for source and destination and makes piece move 
	   Uses:
	   - for input: checkInputValid, isSquareEmpty, isTurnCorrect
	   - for moving: makeMove, 
	*/
	void submitMove(const char* source, const char* destination);


private:
	Piece* board[X_MAX][Y_MAX];
	int turn;
};

#endif //CHESSBOARD_H