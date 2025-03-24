// game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Game {
public:
    enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
    enum Cell { EMPTY, X, O };

    Game();                     // Constructor
    void play(int move);       // Make a move (0 to 8, for 3x3 board)
    Status status() const;     // Return game status
    void display() const;      // Show board

    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    std::vector<Cell> board;   // Flat vector of 9 cells
    bool player1_turn;         // True = Player 1's turn, False = Player 2's
    Status current_status;

    void checkStatus();        // Updates current_status
};

#endif