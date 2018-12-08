chess: ChessMain.o ChessBoard.o Piece.o Bishop.o King.o Knight.o Pawn.o Queen.o Rook.o
	g++ -Wall -g ChessMain.o ChessBoard.o Piece.o Bishop.o King.o Knight.o Pawn.o Queen.o Rook.o -o chess

%.o: %.cpp
	g++ -Wall -g -c $<

main.o: ChessBoard.h 

ChessBoard.o: ChessBoard.h Piece.h Bishop.h King.h Knight.h Pawn.h Queen.h Rook.h

.PHONY: clean

clean:
	rm -f ChessBoard *.o