/*****************************************************/ 
/*  This is the header file Bishop.h
	This is the interface for the class Bishop
*/
/*****************************************************/

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "piece.h"
using namespace std;

class Bishop : public Piece
{
public:
	// Inherits default constructor from Piece (isWhite/x/y)
	Bishop();

	// Inherits default virtual deconstructor from Piece
	~Bishop();

	// Check if Bishop can move to destination based on its rules
	// Can only move diagonally 
	bool checkMoveValid(string destination) const;

	// Displays colour and 'B' when printed
	void printPiece() const;

}; // Bishop

#endif