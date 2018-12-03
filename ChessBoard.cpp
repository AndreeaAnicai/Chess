/*****************************************************/ 
/*  This is the implementation file ChessBoard.cpp	8
*/
/*****************************************************/

#include "ChessBoard.h"
#include "Piece.h"

ChessBoard::ChessBoard()
{
	// FOR A 8 X 8 BOARD 

	// Initialise middle rows with null pointers / empty pieces
	// A-H/2-5 for a 8x8 board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 2; j < 6; j++)
        {
            board[i][j] = NULL;
        }
    }
    // Initialise rows A-H/1 and A-H/6 to pawns 
    for (int i = 0; i < 8; i++)
    {
    	board[i][1] = new Pawn(true, i, 1);
    	board[i][6] = new Pawn(false, i, 6);
    }
    // Initialise rooks
    board[0][0] = new Rook(true, 0, 0);
    board[7][0] = new Rook(true, 7, 0);
    board[0][7] = new Rook(false, 0, 7);
    board[7][7] = new Rook(false, 7, 7);
    // Initialise Knights 
    board[1][0] = new Knight(true, 1, 0);
    board[6][0] = new Knight(true, 6, 0);
    board[1][7] = new Knight(false, 1, 7);
    board[6][7] = new Knight(false, 6, 7);
    // Initialise Bishops 
    board[2][0] = new Bishop(true, 2, 0);
    board[5][0] = new Bishop(true, 5, 0);
    board[2][7] = new Bishop(false, 2, 7);
    board[5][7] = new Bishop(false, 5, 7);
    // Initialise Queens
    board[3][0] = new Queen(true, 3, 0);
    board[3][7] = new Queen(false, 3, 7);
    // Initialise Kings
    board[4][0] = new King(true, 4, 0);
    board[4][7] = new King(false, 4, 7);
}

ChessBoard::~ChessBoard()
{
    for (int i = 0; i < MAX_DIMENSION; i++)
    {
        for (int j = 0; j < MAX_DIMENSION; j++)
        {
            delete[] board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}

ChessBoard* ChessBoard::getBoard() {
    if (!thisChessBoard) 
        thisChessBoard = new ChessBoard();
    else 
        return thisChessBoard;
}

bool ChessBoard::isSquareOccupied() const {

    if board[x][y] == NULL
        return 1;
    return 0;
}

void ChessBoard::setPieceCoord (Piece& piece, int x, int y) {
    piece.xCoord = x;
    piece.yCoord = y;
}

bool ChessBoard::checkVertical( fromSquare,  toSquare) const {

}
    
bool ChessBoard::checkHorizontal( fromSquare,  toSquare) const {

}

bool ChessBoard::checkDiagonal( fromSquare, toSquare) const {

}
    
void ChessBoard::submitMove (Player& player, fromSquare, toSquare) const {

}

void ChessBoard::printBoard(ostream& outStream) const
{
    outStream << endl << "   A  B  B  B  E  F  G  H" << endl;
    outStream << " -------------------------" << endl;
    for (int y = MAX_DIMENSION - 1; y >= 0; y--) 
    {
        outStream << y + 1;
        for (int x = 0; x < MAX_DIMENSION; x++)
        {
            outStream << "|";
            if(board[x][y]->isSquareOccupied())
                board[x][y]->printPiece();
            else
                outStream << "  ";
        }
        outStream << "|" << y + 1 << endl << " -------------------------" << endl;
    }
    outStream << "   A  B  C  D  E  F  G  H" << endl << endl;
}

ChessBoard* ChessBoard::thisChessBoard = NULL;

