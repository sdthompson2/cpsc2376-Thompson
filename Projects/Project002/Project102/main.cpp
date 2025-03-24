#include "game.h"
#include <iostream>

int main() {
    Game game;
    int move;

    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Player 1 = X, Player 2 = O\n";
    std::cout << "Use numbers 0-8 to place your mark on the board:\n";
    std::cout << " 0 | 1 | 2\n";
    std::cout << " 3 | 4 | 5\n";
    std::cout << " 6 | 7 | 8\n\n";

    // Keep playing until someone wins or it's a draw
    while (game.status() == Game::ONGOING) {
        std::cout << game;
        std::cout << "Enter your move (0-8): ";
        std::cin >> move;
        game.play(move);
    }

    std::cout << game;

    // Announce result
    if (game.status() == Game::PLAYER_1_WINS)
        std::cout << "Player 1 wins!\n";
    else if (game.status() == Game::PLAYER_2_WINS)
        std::cout << "Player 2 wins!\n";
    else
        std::cout << "Sorry, you tied! Another round?\n";

    return 0;
}