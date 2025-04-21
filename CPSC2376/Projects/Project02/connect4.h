#ifndef CONNECT4_H
#define CONNECT4_H

#include <vector>
#include <iostream>

enum Cell { EMPTY, X, O };
enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

class Connect4 {
public:
    Connect4(int rows = 6, int cols = 7);

    bool play(int col);
    Status status() const;
    int getCurrentPlayer() const;

    friend std::ostream& operator<<(std::ostream& os, const Connect4& game);

private:
    int rows, cols;
    std::vector<std::vector<Cell> > board;
    int currentPlayer;

    bool dropToken(int col);
    bool checkWin(int lastRow, int lastCol) const;
    bool isBoardFull() const;
};

#endif
