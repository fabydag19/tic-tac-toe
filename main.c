#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define m 3 // Matrix dimensions

// Functions declaration
void game();
bool checkGame(char grid[m][m]);

int main(void)
{
    printf("****************************************************\n");
    printf("                     Tic Tac Toe                    \n");
    printf("****************************************************\n\n");
    game();
    return 0;
}

// Game function
void game()
{
    char matrix[m][m] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int playerMove, switchPlayer;
    char sign;

    while (true){
        // Print game board
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                if (j == 2) {
                    printf(" %c\n", matrix[i][j]);
                    if (i != 2) printf(" ---------\n");
                }
                else printf(" %c |", matrix[i][j]);
            }
        }
        printf("\n****************************************************\n");

        if (switchPlayer % 2 == 0) {
            printf("\nPlayer 1 (X): ");
            sign = 'X';
        }
        else {
            printf("\nPlayer 2 (O): ");
            sign = 'O';
        }
        scanf("%d", &playerMove);
        switch (playerMove) {
            case 1:
                matrix[0][0] = sign;
                break;
            case 2:
                matrix[0][1] = sign;
                break;
            case 3:
                matrix[0][2] = sign;
                break;
            case 4:
                matrix[1][0] = sign;
                break;
            case 5:
                matrix[1][1] = sign;
                break;
            case 6:
                matrix[1][2] = sign;
                break;
            case 7:
                matrix[2][0] = sign;
                break;
            case 8:
                matrix[2][1] = sign;
                break;
            case 9:
                matrix[2][2] = sign;
                break;
            default:
                printf("Choice not valid!\n");
        }        

        bool c = checkGame(matrix);
        if (c == true) {
            printf("Win!");
            break;
        }

        switchPlayer++;
    }
}

// Cheack combinations
bool checkGame(char grid[m][m]) {

    // Horizontal combinations
    for(int i = 0; i < m; i++){
        if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]){
            return true;
        }
    }

    // Vertical combinations
    for(int i = 0; i < 3; i++){
        if(grid[0][i] == grid[1][i] && grid[0][1] == grid[2][i]){
            return true;
        }
    }

    // Diagonal combinations
    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) return true;
    else if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) return true;
    else return false;

}