chess: ChessMain.o ChessBoard.o Piece.o Bishop.o King.o Knight.o Pawn.o Queen.o Rook.o
	g++ -std=c++11 -Wall -g ChessMain.o ChessBoard.o Piece.o Bishop.o King.o Knight.o Pawn.o Queen.o Rook.o -o chess

%.o: %.cpp
	g++ -std=c++11 -Wall -g -c $<

main.o: ChessBoard.h 

ChessBoard.o: ChessBoard.h Piece.h Bishop.h King.h Knight.h Pawn.h Queen.h Rook.h

.PHONY: clean

clean:
	rm -f ChessBoard *.o