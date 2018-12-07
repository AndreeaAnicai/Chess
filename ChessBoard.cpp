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
#include <stdio.h>
#include <string.h>
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
    initialiseBoard();
    cerr << "A new chess game is started!" << endl;
}

ChessBoard::~ChessBoard() {

    for (int i = 0; i < X_MAX; i++) {
        for (int j = 0; j < Y_MAX; j++) {
            delete board[i][j];
        }
       // delete[] board[i];
    }
   // delete[] board;
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
                    cout << "W" << board[x][y]->getPieceInitial();
                else 
                    cout << "B" << board[x][y]->getPieceInitial();
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
    initialiseBoard();
    turn = 0;
}

/************************** CHECK USER INPUT AND SET COORDINATES ***************************/

bool ChessBoard::checkInputValid(const char* input, int coordinates[2]) {
    char fileChar = input[0]; 
    char rankChar = input[1];

    if (strlen(input) != 2 || 
        fileChar < 'A' || fileChar > 'H' || 
        //fileChar < 'a' || fileChar > 'h' || 
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

bool ChessBoard::isTurnCorrect(bool isWhite) {
    cout << "turn is: " << turn << endl;
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
void ChessBoard::tryMove(int source[2], int destination[2], Piece* playerPiece) {
    // Get coordinates from arrays
    int xSource = source[0];
    int ySource = source[1];
    int xDestination = destination[0];
    int yDestination = destination[1]; 
    // Update board
    board[xDestination][yDestination] = playerPiece;
    board[xSource][ySource] = NULL;
    playerPiece->setXYCoord(xDestination, yDestination);
}
void ChessBoard::undoMove(int source[2], int destination[2], Piece* playerPiece) {
    // Get coordinates from arrays
    int xSource = source[0];
    int ySource = source[1];
    int xDestination = destination[0];
    int yDestination = destination[1]; 
    // Update board
    board[xSource][ySource] = board[xDestination][yDestination];
    board[xDestination][yDestination] = NULL;
    playerPiece->setXYCoord(xSource, ySource);
}
void ChessBoard::makeMove(int source[2], int destination[2], Piece* playerPiece) {
    // Set target piece 
    Piece* targetPiece = board[destination[0]][destination[1]];
    // If target not null -> attempt move and check if legal
    if (targetPiece != NULL)
        cerr << " taking " << targetPiece->getPieceColour() << "'s " << targetPiece->getPieceName();
    // Step into future 
    tryMove(source,destination,playerPiece);
    // If pawn/ king/ rook-> no longer first move 
    char name = playerPiece->getPieceInitial();
    if ((name == 'P') || (name == 'K') || (name == 'R'))
        playerPiece->updateFirstMove();
    // Increment turn
    turn++;
}
void ChessBoard::getKingCoord (bool playerColour, int kingCoord[2]) {
    for (int i = 0; i < X_MAX; i++) {
        for (int j = 0; j < Y_MAX; j++) {
            if (board[i][j] != NULL) {
                // Check if piece is the King of same colour
                if ((board[i][j]->getPieceInitial() == 'K') && (board[i][j]->isPieceWhite() == playerColour)) {
                    kingCoord[0] = i;
                    kingCoord[1] = j;
                    return;
                }
            }
        }
    }
}
bool ChessBoard::isInCheck (bool playerColour) {
    int kingCoord[2];
    getKingCoord(playerColour, kingCoord);
    for (int i = 0; i < X_MAX; i++) {
        for (int j = 0; j < Y_MAX; j++) {
            if (board[i][j] != NULL) { // there is a piece
                if (board[i][j]->isPieceWhite() != playerColour) { // enemy piece
                    if (board[i][j]->isValidMove(kingCoord, board)) // enemy pieces can move to king's location
                        return true;
                }
            }
        }
    } 
    return false; 

}
bool ChessBoard::moveSafeFromCheck (int source[2], int destination[2]) {
    bool valid = true;
    int xSource = source[0];
    int ySource = source[1];
    int xDestination = destination[0];
    int yDestination = destination[1]; 
    Piece* playerPiece = NULL;
    Piece* temp = NULL;

    if (board[xSource][ySource] != NULL)
        playerPiece = board[xSource][ySource];
    if (board[xDestination][yDestination] != NULL) 
        temp = board[xDestination][yDestination]; // Keep the piece at destination square
    tryMove(source, destination, playerPiece);
    if (isInCheck(playerPiece->isPieceWhite()))  // Check if move puts player in check
        valid = false;
    undoMove(source, destination, playerPiece);
    if (temp != NULL) 
        board[xDestination][yDestination] = temp; // Restore the piece at destination if move invalid
    return valid;
}
bool ChessBoard::moveLeadsToCheckmate (bool playerColour) {
    // Iterate through all non-null pieces 
    for (int i = 0; i < X_MAX; i++) { 
        for (int j = 0; j < Y_MAX; j++) {

            if (board[i][j] != NULL) { 
                int source[] = {i, j}; // Get source coordinates
                if (board[i][j]->isPieceWhite() == playerColour) { // Consider only own pieces
                    // Iterate through all possible destinations on board
                    for (int x = 0; x < X_MAX; x++) {  
                        for (int y = 0; y < Y_MAX; y++) {
                            int destination[] = {x, y}; // Get destination coordinates 
                            // If there is a valid move to that destination AND
                            // the move doesn't result in check then 
                            if ((board[i][j]->isValidMove(destination, board)) && (moveSafeFromCheck(source, destination))) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }                            
    return false;
}

/******************************** CHECK AND SUBMIT MOVE ************************************/

void ChessBoard::submitMove(const char* sourceInput, const char* destinationInput) {

    // Read input and put into arrays
    int source[2], destination[2];
    if (!checkInputValid(sourceInput, source)) 
        return;
    if (!checkInputValid(destinationInput, destination)) 
        return;

    // Initialise our piece to correct starting position
    Piece* playerPiece = board[source[0]][source[1]];

    // Check for empty piece
    if (playerPiece == NULL) {
        cerr << "There is no piece at position " << sourceInput << "!" << endl;
        return;
    }
    else {
        const char* playerPieceColour = playerPiece->getPieceColour(); 
        const char* playerPieceName = playerPiece->getPieceName();
    
        // Check turn 
        bool playerColour = playerPiece->isPieceWhite();
        if (!isTurnCorrect(playerColour)) 
            return;

        // Check moving that piece is valid
        //if (!playerPiece->isValidMove(destination, board) || !moveSafeFromCheck(source, destination)) {
        if (!playerPiece->isValidMove(destination, board)) {
            cerr << playerPieceColour << "'s " << playerPieceName;
            cerr << " cannot move to " << destinationInput << ". Invalid move" << endl;
            return;
        }
        if (!moveSafeFromCheck(source, destination)) {
            cerr << playerPieceColour << "'s " << playerPieceName;
            cerr << " cannot move to " << destinationInput << ".  Self check" << endl;
            return;
        }
        cerr << playerPieceColour << "'s " << playerPieceName;
        cerr << " moves from " << sourceInput << " to " << destinationInput;

        // Make move
        makeMove(source, destination, playerPiece);

        // Check for checkmate or stalemate  
        const char* enemyPieceColour = "White";
        bool enemyColour = !playerColour;
        bool enemyInCheck = isInCheck(enemyColour);
        bool enemyHasLegalMove = moveLeadsToCheckmate(enemyColour);
        if (!enemyColour)
            enemyPieceColour = "Black";

        if (!enemyHasLegalMove) { 
            if (enemyInCheck)
                cerr << enemyPieceColour << " is in checkmate" << endl;
            else
                cerr << enemyPieceColour << " is in stalemate" << endl;
            printBoard();
            resetBoard();
            return;
        } 
        else if (enemyInCheck) {
            cerr << enemyPieceColour << " is in check";
        }
    }
    printBoard();
}
