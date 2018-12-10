/******************************************************/
/* 
    Andreea Anicai - MSc Computing 2018
    This is the implementation file of the class Knight 
*/
/******************************************************/

#include "Knight.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Knight::Knight(int xCoord, int yCoord, bool colour) : Piece(xCoord, yCoord, colour, 'N'){
    // Body intentionally empty
}

Knight::~Knight() {
    // Body intentionally empty
}

bool Knight::isDirectionClear(int xTranslation, int yTranslation, Piece* targetPiece, Piece *board[X_MAX][Y_MAX]) {
    // Skips the checking of pieces on the way
    if (targetPiece != NULL && (targetPiece->isPieceWhite() == isWhite)) {
        return false; 
    }
    return true;
}
    
bool Knight::isMoveLegal(int xTranslation, int yTranslation) {
    if (abs(xTranslation) != 1 && abs(xTranslation) != 2) {
        return false;
    }
    if (abs(yTranslation) != 1 && abs(yTranslation) != 2) { 
        return false;
    }
    if (abs(xTranslation) == abs(yTranslation)) { //Diagonal not L shaped
        return false;
    }
    if (xTranslation == 0 && yTranslation == 0) { //Piece not moving
        return false;
    }
    return true;
}
