#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define m 3 // Matrix dimensions

// Functions declaration
void startGame();
void printBoard(char grid[m][m]);
bool checkWinner(char grid[m][m]);

int main(void)
{
    printf("****************************************************\n");
    printf("                     Tic Tac Toe                    \n");
    printf("****************************************************\n");
    startGame();
    return 0;
}

// Setup of game board
void printBoard(char grid[m][m]) {
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (j == 2) {
                printf(" %c\n", grid[i][j]);
                if (i != 2) printf(" ---------\n");
            }
             else printf(" %c |", grid[i][j]);
        }
    }
    printf("\n****************************************************\n");
}


void startGame()
{
    char matrix[m][m] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int playerMove;
    char sign;

    int switchPlayer = 0;

    while (true){
        // Print game board
        printBoard(matrix);

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
            if ((matrix[x][y] == 'X') || (matrix[x][y] == 'O')) printf("Choose another box!\n");
            else {
                matrix[x][y] = sign;
                break;
            }
        }

        bool c = checkWinner(matrix); // Check game combinations to verify the win
        // Check the winning player 
        if ((c == true) && (switchPlayer % 2 == 0)) {
            printf("Player 1 Win!\n");
            break;
        }
        else if ((c == true) && (switchPlayer % 2 != 0)) {
            printf("Player 2 Win!\n");
            break;
        }

        switchPlayer++;
        // Check if the counter is greater than maximum number of plays
        if (switchPlayer > 8) {
            printf("It's a draw. No winner!\n");
            break;
        }
    }
}

// Cheack combinations
bool checkWinner(char grid[m][m]) {

    // Horizontal combinations
    for(int i = 0; i < m; i++){
        if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]){
            return true;
        }
    }

    // Vertical combinations
    for(int i = 0; i < m; i++){
        if(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]){
            return true;
        }
    }

    // Diagonal combinations
    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) return true;
    else if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) return true;
    else return false;

}