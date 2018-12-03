/******************************************************/
/* This is the implementation file of the class Knight */
/******************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

Knight::Knight(int xCoord, int yCoord, bool colour) : Piece(xCoord, yCoord, colour, 'N'){
    // Body intentionally empty
}

Knight::~Knight() {
    // Body intentionally empty
}

bool Knight::pathIsClear(int xTranslation, int yTranslation, ChessPiece* targetPiece, ChessPiece *board[X_MAX][Y_MAX]) override {
    bool valid = true;
    // Skips the checking of pieces on the way
    if (targetPiece != NULL && (targetPiece->isWhite() == isWhite)) {
        valid = false; 
    }
    return valid;
}
    
bool Knight::displacementOK(int xTranslation, int yTranslation) {
    bool valid = true;
    if (abs(xTranslation) != 1 && abs(xTranslation) != 2) {
        valid = false;
    }
    if (abs(yTranslation) != 1 && abs(yTranslation) != 2) { 
        valid = false;
    }
    if (abs(xTranslation) == abs(yTranslation)) { //Diagonal not L shaped
        valid = false;
    }
    if (xTranslation == 0 && yTranslation == 0) { //Piece not moving
        valid = false;
    }
    return valid;
}