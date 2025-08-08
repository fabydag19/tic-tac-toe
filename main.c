#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define m 3 // Board dimensions

// Functions declaration
void startGame();
void printBoard(char board[m][m]);
bool checkWinner(char board[m][m]);

int main(void) {
    printf("****************************************************\n");
    printf("                     Tic Tac Toe                    \n");
    printf("****************************************************\n");
    startGame();
    return 0;
}

// Setup of game board
void printBoard(char board[m][m]) {
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (j == 2) {
                printf(" %c\n", board[i][j]);
                if (i != 2) printf(" ---------\n");
            }
             else printf(" %c |", board[i][j]);
        }
    }
    printf("\n****************************************************\n");
}

// Start game
void startGame() {
    char board[m][m] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int playerMove;
    char sign;
    int switchPlayer = 0;

    while (true){
        // Print game board
        printBoard(board);

        // Check the winning player 
        if ((checkWinner(board) == true) && ((switchPlayer - 1) % 2 == 0)) {
            printf("Player 1 Win!\n");
            break;
        }
        else if ((checkWinner(board) == true) && ((switchPlayer - 1) % 2 != 0)){
            printf("Player 2 Win!\n");
            break;
        }

        // Check if the counter is greater than maximum number of plays
        if (switchPlayer > 8) {
            printf("It's a draw. No winner!\n");
            break;
        }

        while (true) {
            // Switch the player shift
            if (switchPlayer % 2 == 0) {
                printf("\nPlayer 1 (X): ");
                sign = 'X';
            }
            else {
                printf("\nPlayer 2 (O): ");
                sign = 'O';
            }
            // Check the input if it is a int type and is between 1 and 9
            if (scanf("%d", &playerMove) != 1 || playerMove < 1 || playerMove > 9) {
                printf("Invalid input. Enter a number between 1 and 9.\n");
                while(getchar() != '\n'); // Clean buffer input
                continue;
            }
            int x = (playerMove - 1) / m; // Calculate row
            int y = (playerMove - 1) % m; // Calculate column
            if ((board[x][y] == 'X') || (board[x][y] == 'O')) printf("Choose another box!\n");
            else {
                board[x][y] = sign;
                break;
            }
        }
        switchPlayer++;
    }
}

// Cheack combinations
bool checkWinner(char board[m][m]) {
    // Horizontal combinations
    for(int i = 0; i < m; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return true;
        }
    }

    // Vertical combinations
    for(int i = 0; i < m; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return true;
        }
    }

    // Diagonal combinations
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) return true;
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) return true;
    else return false;
}