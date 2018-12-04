/*****************************************************/ 
/*  This is the implementation file ChessBoard.cpp	8
*/
/*****************************************************/

#include "ChessBoard.h"
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/******************************* BOARD FUNCTIONALITY *********************************/

// Initialise vectors to store captured pieces 
vector<Piece*> whitePieces;
vector<Piece*> blackPieces;

ChessBoard::ChessBoard() : turn(0) {
    for (int i = 0; i < X_MAX; i++) {
        for (int j = 0; j < Y_MAX; j++) {
            board[i][j] = NULL;
        }
    }
}

ChessBoard::~ChessBoard() {

    resetBoard(); 
    for (int i = 0; i < X_MAX; i++) {
        for (int j = 0; j < Y_MAX; j++) {
            delete board[i][j];
        }
        //delete[] board[i];
    }
    //delete[] board;
}

void ChessBoard::initialiseBoard() {

    // Initialise Pawns on rows 1 and 6
    for (int i = 0; i < X_MAX; i++) {
        board[i][1] = new Pawn(i,1,true); // White pawns
        board[i][6] = new Pawn(i,6,false); // Black pawns
    }
    // Initialise Rooks
    board[0][0] = new Rook(0,0,true); // 2 x white
    board[7][0] = new Rook(7,0,true);
    board[0][7] = new Rook(0,7,false); // 2 x black
    board[7][7] = new Rook(7,7,false); 
    // Initialise Knights
    board[1][0] = new Knight(1,0,true); // 2 x white
    board[6][0] = new Knight(6,0,true);
    board[1][7] = new Knight(1,7,false); // 2 x black
    board[6][7] = new Knight(6,7,false); 
    // Initialise Bishops
    board[2][0] = new Bishop(2,0,true); // 2 x white
    board[5][0] = new Bishop(5,0,true);
    board[2][7] = new Bishop(2,7,false); // 2 x black
    board[5][7] = new Bishop(5,7,false); 
    // Initialise Queens
    board[3][0] = new Queen(3,0,true); // White queen
    board[3][7] = new Queen(3,7,false); // Black queen
    // Initialise Kings
    board[4][0] = new King(4,0,true); // White king
    board[4][7] = new King(4,7,false); // Black kings
}

void ChessBoard::printBoard() {
    
    cout << endl << "   A  B  C  D  E  F  G  H" << endl;
    cout << " -------------------------" << endl;
    for (int y = Y_MAX - 1; y >= 0; y--) // black at top, white at bottom
    {
        cout << y + 1;
        for (int x = 0; x < X_MAX; x++)
        {
            cout << "|";
            if(board[x][y] != NULL) {
                if (board[x][y]->isPieceWhite()) 
                    cout << "W" << board[x][y]->getPieceName();
                else 
                    cout << "B" << board[x][y]->getPieceName();
            }
            else 
                cout << "  ";
        }
        cout << "|" << y + 1 << endl << " -------------------------" << endl;
    }
    cout << "   A  B  C  D  E  F  G  H" << endl << endl;
}

void ChessBoard::resetBoard() {
    for (int i = 0; i < X_MAX; i++) {
        for (int j = (Y_MAX - 1); j >= 0; j--) {
            if (board[i][j] != NULL) {
                delete board[i][j];   
                board[i][j] = NULL;   
            }
        }
    }
}
turn = 0;

/******************** FOR PRINTING THE PIECE NAME *****************/

const char* ChessBoard::printPieceName(Piece* piece) {
    char name = piece->getPieceName();
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
const char* ChessBoard::printPieceColour(Piece* piece) {
    const char* colour = "White";
    if (piece->isPieceWhite)
        colour = "Black";
    return colour;
}
/************************** CHECK USER INPUT AND SET COORDINATES ***************************/

bool ChessBoard::checkInputValid(const char* input, int coordinates[2]) {
    char fileChar = input[0]; 
    char rankChar = input[1];

    if (strlen(input) != 2 || 
        fileChar < 'A' || fileChar > 'H' || 
        fileChar < 'a' || fileChar > 'h' || 
        rankChar < '1' || rankChar > '8' ) {
        cerr << "Your inputted move, " << input << ", is invalid." << endl;
        return false;
    }
    else { // Update array if input is valid 
        int fileInt = fileChar - 'A';     // Transform char to int    
        int rankInt = rankChar - '0' - 1; // Transform char to int (-1 for 0 indexing)  
        coordinates[0] = fileInt;
        coordinates[1] = rankInt;
    }
    return true;
}

bool ChessBoard::isSquareEmpty(Piece* currentSquare, const char* source) {
    if (currentSquare == NULL) {
        cerr << "There is no piece at position " << source << "!" << endl;
        return true;
    }
    return false;
}

bool ChessBoard::isTurnCorrect(bool isWhite) {
    if ((turn % 2 == 0 && !isWhite) || (turn % 2 == 1 && isWhite)) {
        if (isWhite) {
            cerr << "It is not White's turn to move!" << endl;
            return false; 
        }
        else {
            cerr << "It is not Black's turn to move!" << endl;
            return false;  
        }
    }
    return true;
}

void ChessBoard::makeMove(int source[2], int destination[2], Piece* playerPiece) {
    // Set target piece 
    Piece* targetPiece = board[destination[0]][destination[1]];

    // If target not null -> attempt move and check if legal
    if (targetPiece != NULL) {
        cerr << " taking " << printPieceColour(targetPiece) << "'s " << printPieceName(targetPiece);
    }
    // Step into future 

    // If pawn/ king/ rook-> no longer first move 
    if (strcmp(playerPiece->name,'P'))
        playerPiece->isFirstMove = false;
    if (strcmp(playerPiece->name,'K'))
        playerPiece->isFirstMove = false;
    if (strcmp(playerPiece->name,'R'))
        playerPiece->isFirstMove = false;

    // Increment turn
    turn++;
}
void ChessBoard::tryMove(int source[2], int destination[2], Piece* playerPiece) {

}
void ChessBoard::undoMove(int source[2], int destination[2], Piece* playerPiece) {
    
}

/******************************** CHECK AND SUBMIT MOVE ************************************/

void ChessBoard::submitMove(const char* source, const char* destination) {

}

