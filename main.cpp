#include <iostream>
#include "Board.h"
// #include "Piece.h"
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {

    Board board;
    string startingPosition = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    string random = "rn2k2r/pp3ppp/1qpb1n2/3p2B1/3P1p2/N1PQ1NPb/PP2P2P/3RK2R";
    board.readFromFenString(random);

    cout << "Hello World!" << endl;

    return 0;
}