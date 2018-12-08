#include "ChessBoard.h"

#include <iostream>
#include "ChessBoard.h"
#include <vector>

using namespace std;

int main() {

    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;

    ChessBoard cb;
    cout << endl;
  /*
  
    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;
  */

    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;

    cb.resetBoard();

/*
    cout << "===========================" << endl;
    cout << "Testing check with pawn" << endl;
    cout << "===========================" << endl;
    cout << endl;
    
    cb.submitMove("D2", "D3");
    cb.submitMove("E7", "E5");
    cout << endl;

    cb.submitMove("G1", "H3");
    cb.submitMove("E5", "E4");
    cout << endl;

    cb.submitMove("H3", "G1");
    cb.submitMove("E4", "E3");
    cout << endl;

    cb.submitMove("G1", "H3");
    cb.submitMove("E8", "E7");
    cout << endl;

    cb.submitMove("H3", "G1");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("G1", "H3");
    cb.submitMove("E6", "E5");
    cout << endl;

    cb.submitMove("D3", "D4");
    cout << endl;
    
    cb.resetBoard();


    cout << "===========================" << endl;
    cout << "Testing checkmate with pawn" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.submitMove("C2", "C3");
    cb.submitMove("E7", "E5");
    cout << endl;

    cb.submitMove("H2", "H4");
    cb.submitMove("E5", "E4");
    cout << endl;

    cb.submitMove("H4", "H5");
    cb.submitMove("E4", "E3");
    cout << endl;

    cb.submitMove("H5", "H6");
    cb.submitMove("E8", "E7");
    cout << endl;

    cb.submitMove("F2", "E3");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("G2", "G3");
    cb.submitMove("E6", "E5");
    cout << endl;

    cb.submitMove("A2", "A3");
    cb.submitMove("E5", "E4");
    cout << endl;

    cb.submitMove("H1", "H5");
    cb.submitMove("A7", "A6");

    cout << endl;
    cb.submitMove("D1", "B3");
    cout << endl;

    cb.submitMove("E4", "E3");
    cb.submitMove("A6", "A5");
    cout << endl;

    cb.submitMove("D2", "D3");
    cb.submitMove("A5", "A4");
    cout << endl;

    cb.resetBoard();


    cout << "===========================" << endl;
    cout << "Testing if King can kill attacker\nNow King in Checkmate" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.submitMove("C2", "C3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("D1", "B3");
    cb.submitMove("A7", "A6");
    cout << endl;

    cb.submitMove("E2", "E3");
    cb.submitMove("A6", "A5");
    cout << endl;

    cb.submitMove("F1", "C4");
    cb.submitMove("A5", "A4");
    cout << endl;

    cb.submitMove("C4", "F7");
    cout << endl;

    cb.resetBoard();


    cout << "===========================" << endl;
    cout << "Testing if King can kill attacker" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.submitMove("C2", "C3");
    cb.submitMove("E7", "E5");
    cout << endl;

    cb.submitMove("D1", "B3");
    cb.submitMove("A7", "A6");
    cout << endl;

    cb.submitMove("B3", "F7");
    cb.submitMove("E8", "F7");
    cout << endl;
    
    cb.resetBoard();

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E5");
    cout << endl;

    cb.submitMove("G1", "F3");
    cb.submitMove("B8", "C6");
    cout << endl;

    cb.submitMove("F1", "C4");
    cb.submitMove("F8", "C5");
    cout << endl;

    cb.submitMove("E1", "G1");
    cout << endl;

    cout << "===========================" << endl;
    cout << " Paul Morphy v Duke Karl" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E5");
    cout << endl;

    cb.submitMove("G1", "F3");
    cb.submitMove("D7", "D6");
    cout << endl;
    
    cb.submitMove("D2", "D4");
    cb.submitMove("C8", "G4");
    cout << endl;
    
    cb.submitMove("D4", "E5");
    cb.submitMove("G4", "F3");
    cout << endl;
    
    cb.submitMove("D1", "F3");
    cb.submitMove("D6", "E5");
    cout << endl;
    
    cb.submitMove("F1", "C4");
    cb.submitMove("G8", "F6");
    cout << endl;
    
    cb.submitMove("F3", "B3");
    cb.submitMove("D8", "E7");
    cout << endl;
    
    cb.submitMove("B1", "C3");
    cb.submitMove("C7", "C6");
    cout << endl;
    
    cb.submitMove("C1", "G5");
    cb.submitMove("B7", "B5");
    cout << endl;
    
    cb.submitMove("C3", "B5");
    cb.submitMove("C6", "B5");
    cout << endl;
    
    cb.submitMove("C4", "B5");
    cb.submitMove("B8", "D7");
    cout << endl;
    
    cb.submitMove("E1", "C1");
    cb.submitMove("A8", "D8");
    cout << endl;
    
    cb.submitMove("D1", "D7");
    cb.submitMove("D8", "D7");
    cout << endl;
    
    cb.submitMove("H1", "D1");
    cb.submitMove("E7", "E6");
    cout << endl;
    
    cb.submitMove("B5", "D7");
    cb.submitMove("F6", "D7");
    cout << endl;

    cb.submitMove("B3", "B8");
    cb.submitMove("D7", "B8");
    cout << endl;
    
    cb.submitMove("D1", "D8");
    cout << endl;

    cb.resetBoard();
*/
    return 0;
}
