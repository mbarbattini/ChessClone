#ifndef BOARD_H
#define BOARD_H

#include <string>

class Board {
public:
    int grid[8][8] = {0};
    // 0: white, 1: black
    bool playerToMove;
    Board();
    void readFromFenString(std::string);
};

#endif