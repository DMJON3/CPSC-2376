#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <utility> // for std::pair

using namespace std;

// Enums
enum class Cell { EMPTY, PLAYER1, PLAYER2 };
enum class GameState { ONGOING, PLAYER1_WINS, PLAYER2_WINS, DRAW };

// Function Prototypes
void printRules();
void printBoard(const vector<vector<Cell>>& board);
vector<vector<Cell>> makeBoard(int rows, int cols);
bool dropToken(vector<vector<Cell>>& board, int col, int player);
bool usePower(vector<vector<Cell>>& board, int col, int player);
GameState gameStatus(const vector<vector<Cell>>& board);
int getColumnInput(int player, int cols, bool powerAvailable);
bool isBoardFull(const vector<vector<Cell>>& board);
string cellToStr(Cell cell);

// Main Function
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    printRules();

    while (true) {
        int rows, cols;
        cout << "Enter board rows (min 4): ";
        cin >> rows;
        cout << "Enter board columns (min 4): ";
        cin >> cols;

        if (rows < 4 || cols < 4) {
            cout << "Board size must be at least 4x4.\n";
            continue;
        }

        vector<vector<Cell>> board = makeBoard(rows, cols);
        bool powerUsed[3] = { false, false, false }; // 0 unused, 1 for player1, 2 for player2

        int currentPlayer = rand() % 2 + 1;
        GameState state = GameState::ONGOING;

        cout << "Player " << currentPlayer << " starts!\n";

        while (state == GameState::ONGOING) {
            printBoard(board);
            bool turnComplete = false;

            while (!turnComplete) {
                int move = getColumnInput(currentPlayer, cols, !powerUsed[currentPlayer]);

                if (move == -1) { // Power token
                    cout << "Enter column to remove opponent’s token: ";
                    int col;
                    cin >> col;

                    if (col >= 0 && col < cols) {
                        if (usePower(board, col, currentPlayer)) {
                            powerUsed[currentPlayer] = true;
                            turnComplete = true;
                        }
                    }
                    else {
                        cout << "Invalid column.\n";
                    }
                }
                else {
                    if (dropToken(board, move, currentPlayer)) {
                        turnComplete = true;
                    }
                    else {
                        cout << "Column full. Try again.\n";
                    }
                }
            }

            state = gameStatus(board);
            if (state == GameState::ONGOING)
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }

        printBoard(board);
        if (state == GameState::PLAYER1_WINS)
            cout << "🎉 Player 1 (X) wins!\n";
        else if (state == GameState::PLAYER2_WINS)
            cout << "🎉 Player 2 (O) wins!\n";
        else
            cout << "🤝 It's a draw!\n";

        cout << "Play again? (y/n): ";
        string again;
        cin >> again;
        if (again != "y" && again != "Y")
            break;
    }

    cout << "Thanks for playing!\n";
    return 0;
}

// ========== Game Logic ==========

void printRules() {
    cout << R"(
=== Connect 4: Speical Edition ===
- Two players take turns dropping tokens into columns.
- First to connect 4 tokens vertically, horizontally, or diagonally wins.
- Each player has ONE 'Power Token' to remove opponent's top token in a column.
  > Type 'power' during your turn to use it.
- Custom board sizes are supported.
=====================================
)" << endl;
}

vector<vector<Cell>> makeBoard(int rows, int cols) {
    return vector<vector<Cell>>(rows, vector<Cell>(cols, Cell::EMPTY));
}

string cellToStr(Cell cell) {
    switch (cell) {
    case Cell::PLAYER1: return "X";
    case Cell::PLAYER2: return "O";
    default: return " ";
    }
}

void printBoard(const vector<vector<Cell>>& board) {
    cout << "\n   ";
    for (int i = 0; i < board[0].size(); ++i)
        cout << " " << i << "  ";
    cout << "\n  +" << string(board[0].size() * 4 - 1, '-') << "+\n";

    for (size_t i = 0; i < board.size(); ++i) {
        cout << "  |";
        for (size_t j = 0; j < board[i].size(); ++j)
            cout << " " << cellToStr(board[i][j]) << " |";
        cout << "\n  +" << string(board[0].size() * 4 - 1, '-') << "+\n";
    }
    cout << endl;
}

bool dropToken(vector<vector<Cell>>& board, int col, int player) {
    for (int i = board.size() - 1; i >= 0; --i) {
        if (board[i][col] == Cell::EMPTY) {
            board[i][col] = (player == 1) ? Cell::PLAYER1 : Cell::PLAYER2;
            return true;
        }
    }
    return false;
}

bool usePower(vector<vector<Cell>>& board, int col, int player) {
    for (int i = 0; i < board.size(); ++i) {
        if (board[i][col] != Cell::EMPTY) {
            Cell top = board[i][col];
            if ((player == 1 && top == Cell::PLAYER2) || (player == 2 && top == Cell::PLAYER1)) {
                for (int j = i; j > 0; --j)
                    board[j][col] = board[j - 1][col];
                board[0][col] = Cell::EMPTY;
                return true;
            }
            else {
                cout << "You can't remove your own token.\n";
                return false;
            }
        }
    }
    cout << "Column is empty.\n";
    return false;
}

GameState gameStatus(const vector<vector<Cell>>& board) {
    int rows = board.size(), cols = board[0].size();

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {

            pair<int, int> directions[] = {
                make_pair(0, 1),   // Horizontal
                make_pair(1, 0),   // Vertical
                make_pair(1, 1),   // Diagonal down-right
                make_pair(1, -1)   // Diagonal down-left
            };

            for (int d = 0; d < 4; ++d) {
                int dr = directions[d].first;
                int dc = directions[d].second;

                Cell start = board[r][c];
                if (start == Cell::EMPTY) continue;

                bool win = true;
                for (int i = 1; i < 4; ++i) {
                    int nr = r + dr * i;
                    int nc = c + dc * i;
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || board[nr][nc] != start) {
                        win = false;
                        break;
                    }
                }

                if (win) {
                    if (start == Cell::PLAYER1) return GameState::PLAYER1_WINS;
                    if (start == Cell::PLAYER2) return GameState::PLAYER2_WINS;
                }
            }
        }
    }

    if (isBoardFull(board))
        return GameState::DRAW;
    return GameState::ONGOING;
}

bool isBoardFull(const vector<vector<Cell>>& board) {
    for (size_t i = 0; i < board.size(); ++i)
        for (size_t j = 0; j < board[i].size(); ++j)
            if (board[i][j] == Cell::EMPTY)
                return false;
    return true;
}

int getColumnInput(int player, int cols, bool powerAvailable) {
    string input;
    while (true) {
        cout << "Player " << player << " - Enter column (0-" << cols - 1 << ")";
        if (powerAvailable) cout << " or 'power'";
        cout << ": ";
        cin >> input;

        if (powerAvailable && input == "power")
            return -1;

        try {
            int col = stoi(input);
            if (col >= 0 && col < cols)
                return col;
        }
        catch (...) {
            // Invalid input, do nothing
        }

        cout << "Invalid input. Try again.\n";
    }
}