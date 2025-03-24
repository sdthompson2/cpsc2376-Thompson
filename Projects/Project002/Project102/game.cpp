#include "game.h"

Game::Game() {
    board = std::vector<Cell>(9, EMPTY); // Fill board with empty cells
    player1_turn = true;
    current_status = ONGOING;
}

void Game::play(int move) {
    // If move is out of range, or cell is not empty, or game is over, do nothing
    if (move < 0 || move >= 9 || board[move] != EMPTY || current_status != ONGOING)
        return;

    // Mark the cell with current player's symbol
    board[move] = player1_turn ? X : O;

    // Check if the game is won or drawn
    checkStatus();

    // Switch turn if game is still going
    if (current_status == ONGOING)
        player1_turn = !player1_turn;
}

Game::Status Game::status() const {
    return current_status;
}

void Game::checkStatus() {
    // Winning combinations (rows, columns, diagonals)
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}             // diagonals
    };

    // Check if any win condition is met
    for (int i = 0; i < 8; ++i) {
        int a = wins[i][0], b = wins[i][1], c = wins[i][2];
        if (board[a] != EMPTY && board[a] == board[b] && board[b] == board[c]) {
            current_status = (board[a] == X) ? PLAYER_1_WINS : PLAYER_2_WINS;
            return;
        }
    }

    // Check if board is full (draw)
    bool full = true;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == EMPTY) {
            full = false;
            break;
        }
    }

    if (full)
        current_status = DRAW;
    else
        current_status = ONGOING;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (int i = 0; i < 9; ++i) {
        char symbol = '.';
        if (game.board[i] == Game::X) symbol = 'X';
        else if (game.board[i] == Game::O) symbol = 'O';

        os << symbol << " ";
        if (i % 3 == 2) os << "\n"; // New line every 3 cells
    }
    return os;
}