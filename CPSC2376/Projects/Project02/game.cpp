#include "connect4.h"

Connect4::Connect4(int rows, int cols)
    : rows(rows), cols(cols), currentPlayer(1),
    board(rows, std::vector<Cell>(cols, EMPTY)) {
}

bool Connect4::play(int col) {
    if (col < 0 || col >= cols) return false;
    return dropToken(col);
}

bool Connect4::dropToken(int col) {
    for (int i = rows - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = (currentPlayer == 1) ? X : O;

            if (!checkWin(i, col)) {
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
            return true;
        }
    }
    return false;
}

bool Connect4::checkWin(int r, int c) const {
    Cell playerCell = board[r][c];
    int directions[4][2] = { {0,1}, {1,0}, {1,1}, {1,-1} };

    for (int d = 0; d < 4; ++d) {
        int dr = directions[d][0];
        int dc = directions[d][1];
        int count = 1;

        // Forward
        for (int step = 1; step < 4; ++step) {
            int nr = r + dr * step;
            int nc = c + dc * step;
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || board[nr][nc] != playerCell)
                break;
            ++count;
        }

        // Backward
        for (int step = 1; step < 4; ++step) {
            int nr = r - dr * step;
            int nc = c - dc * step;
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || board[nr][nc] != playerCell)
                break;
            ++count;
        }

        if (count >= 4) return true;
    }

    return false;
}

bool Connect4::isBoardFull() const {
    for (int c = 0; c < cols; ++c) {
        if (board[0][c] == EMPTY) return false;
    }
    return true;
}

Status Connect4::status() const {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (board[r][c] != EMPTY && checkWin(r, c)) {
                return (board[r][c] == X) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
        }
    }

    if (isBoardFull()) return DRAW;
    return ONGOING;
}

int Connect4::getCurrentPlayer() const {
    return currentPlayer;
}

std::ostream& operator<<(std::ostream& os, const Connect4& game) {
    os << "\n  ";
    for (int c = 0; c < game.cols; ++c)
        os << " " << c << " ";
    os << "\n";

    for (int r = 0; r < game.rows; ++r) {
        os << " |";
        for (int c = 0; c < game.cols; ++c) {
            char symbol = ' ';
            if (game.board[r][c] == X) symbol = 'X';
            else if (game.board[r][c] == O) symbol = 'O';
            os << symbol << "|";
        }
        os << "\n";
    }

    return os;
}
