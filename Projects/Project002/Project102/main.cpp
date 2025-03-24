// main.cpp
#include "game.h"
#include <iostream>

int main() {
    Game game;
    int move;

    while (game.status() == Game::ONGOING) {
        std::cout << game;
        std::cout << "Enter your move (0-8): ";
        std::cin >> move;
        game.play(move);
    }

    std::cout << game;

    switch (game.status()) {
    case Game::PLAYER_1_WINS: std::cout << "Player 1 wins!\n"; break;
    case Game::PLAYER_2_WINS: std::cout << "Player 2 wins!\n"; break;
    case Game::DRAW:          std::cout << "It's a draw.\n"; break;
    default: break;
    }

    return 0;
}