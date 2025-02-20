#include

#define ROWS 6
#define COLS 7

enum GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum Player { PLAYER_1 = 'X', PLAYER_2 = 'O' };

void makeBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}