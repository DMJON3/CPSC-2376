#include <iostream>
#include "connect4.h"

int main() {
    Connect4 game;
    Status currentStatus = ONGOING;

    std::cout << "=== Connect 4: OOP Edition ===\n";

    while (currentStatus == ONGOING) {
        std::cout << game;
        std::cout << "Player " << game.getCurrentPlayer() << ", enter a column (0–6): ";

        int col;
        std::cin >> col;

        if (!game.play(col)) {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        currentStatus = game.status();
    }

    std::cout << game;

    switch (currentStatus) {
    case PLAYER_1_WINS:
        std::cout << "Player 1 (X) wins!\n"; break;
    case PLAYER_2_WINS:
        std::cout << "Player 2 (O) wins!\n"; break;
    case DRAW:
        std::cout << "It's a draw!\n"; break;
    default:
        break;
    }

    return 0;
}
