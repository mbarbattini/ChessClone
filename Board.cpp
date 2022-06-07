#include "Board.h"
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

Board::Board() {
    playerToMove = 0;
}

void Board::readFromFenString(string fen) {
    map<char, int> pieceCharToInt = {
        {'p', 1}, {'n', 2}, {'b', 3}, {'r', 4}, {'k', 5}, {'q', 6}
    };
    int rank = 7;
    int file = 0;
    stringstream ss(fen);
    vector<string> fenParts{};
    string spaceDelimiter = " ";
    size_t pos = 0;
    while ((pos = fen.find(spaceDelimiter)) != string::npos) {
        fenParts.push_back(fen.substr(0, pos));
        fen.erase(0, pos + spaceDelimiter.length());
    }
    // piece positions
    string parts = fenParts[0];
    for (auto ch : parts) {
        if (ch == '/') {
            rank--;
            file = 0;
        } else if (isdigit(ch)) {
            file += ch - '0';
        } else {
            char piece = tolower(ch); 
            grid[rank][file] = pieceCharToInt[piece];
            file++;
        }
    }
    // to move
    parts = fenParts[1];
    playerToMove = (parts == "w") ? 0 : 1;

    // castling
    parts = fenParts[2];
    whiteCastleKingside = (parts.find('K')) ? 1 : 0;
    whiteCastleQueenside = (parts.find('Q')) ? 1 : 0;
    blackCastleKingside = (parts.find('k')) ? 1 : 0;
    blackCastleQueenside = (parts.find('q')) ? 1 : 0;

    // move number
    moveNumber[0] = stoi(fenParts[4]);
    moveNumber[1] = stoi(fenParts[5]);

}