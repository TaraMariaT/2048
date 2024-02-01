#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void initializeBoard(int board[SIZE][SIZE]);
void displayBoard(int board[SIZE][SIZE]);
void addRandomTile(int board[SIZE][SIZE]);
void moveTiles(int board[SIZE][SIZE], char direction);
void slideTiles(int board[SIZE][SIZE], char direction);
void mergeTiles(int board[SIZE][SIZE], char direction);

// Initialize the game board
void initializeBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = 0;
        }
    }
}

// Display the game board
void displayBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}

// Adds a new random tile (2 or 4) to the board
void addRandomTile(int board[SIZE][SIZE]) {
    int emptyCells[SIZE * SIZE][2];
    int count = 0;

    // Find empty cells
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }

    // Add a new tile to a random empty cell
    if (count > 0) {
        int index = rand() % count;
        int value = (rand() % 2 + 1) * 2; // Either 2 or 4
        board[emptyCells[index][0]][emptyCells[index][1]] = value;
    }
}

// Function to move tiles in a specified direction
void moveTiles(int board[SIZE][SIZE], char direction) {
    slideTiles(board, direction);
    mergeTiles(board, direction);
    slideTiles(board, direction);
}

void slideTiles(int board[SIZE][SIZE], char direction) {
    // Sliding tiles in the specified direction
    int i, j, k, temp;

    switch (direction) {
        case 'w': // Slide Up
            for (j = 0; j < SIZE; ++j) {
                k = 0;
                for (i = 0; i < SIZE; ++i) {
                    if (board[i][j] != 0) {
                        temp = board[i][j];
                        board[i][j] = 0;
                        board[k][j] = temp;
                        k++;
                    }
                }
            }
            break;

        case 'a': // Slide Left
            for (i = 0; i < SIZE; ++i) {
                k = 0;
                for (j = 0; j < SIZE; ++j) {
                    if (board[i][j] != 0) {
                        temp = board[i][j];
                        board[i][j] = 0;
                        board[i][k] = temp;
                        k++;
                    }
                }
            }
            break;

        case 's': // Slide Down
            for (j = 0; j < SIZE; ++j) {
                k = SIZE - 1;
                for (i = SIZE - 1; i >= 0; --i) {
                    if (board[i][j] != 0) {
                        temp = board[i][j];
                        board[i][j] = 0;
                        board[k][j] = temp;
                        k--;
                    }
                }
            }
            break;

        case 'd': // Slide Right
            for (i = 0; i < SIZE; ++i) {
                k = SIZE - 1;
                for (j = SIZE - 1; j >= 0; --j) {
                    if (board[i][j] != 0) {
                        temp = board[i][j];
                        board[i][j] = 0;
                        board[i][k] = temp;
                        k--;
                    }
                }
            }
            break;
    }
}

void mergeTiles(int board[SIZE][SIZE], char direction) {
    // Merging adjacent tiles in the specified direction
    int i, j;

    switch (direction) {
        case 'w': // Merge Up
            for (j = 0; j < SIZE; ++j) {
                for (i = 0; i < SIZE - 1; ++i) {
                    if (board[i][j] == board[i + 1][j]) {
                        board[i][j] *= 2;
                        board[i + 1][j] = 0;
                    }
                }
            }
            break;

        case 'a': // Merge Left
            for (i = 0; i < SIZE; ++i) {
                for (j = 0; j < SIZE - 1; ++j) {
                    if (board[i][j] == board[i][j + 1]) {
                        board[i][j] *= 2;
                        board[i][j + 1] = 0;
                    }
                }
            }
            break;

        case 's': // Merge Down
            for (j = 0; j < SIZE; ++j) {
                for (i = SIZE - 1; i > 0; --i) {
                    if (board[i][j] == board[i - 1][j]) {
                        board[i][j] *= 2;
                        board[i - 1][j] = 0;
                    }
                }
            }
            break;

        case 'd': // Merge Right
            for (i = 0; i < SIZE; ++i) {
                for (j = SIZE - 1; j > 0; --j) {
                    if (board[i][j] == board[i][j - 1]) {
                        board[i][j] *= 2;
                        board[i][j - 1] = 0;
                    }
                }
            }
            break;
    }
}

int main() {
    int board[SIZE][SIZE];
    char move;

    // Set seed for random number generation
    srand(time(NULL));

    // Initialize the game board
    initializeBoard(board);

    // Add firts two tiles to the board
    addRandomTile(board);
    addRandomTile(board);

    // Main game loop
    while (1) {
        // Display the game board
        displayBoard(board);

        // Get user input for the next move
        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &move);

        // Create a copy of the board before the move
        int prevBoard[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                prevBoard[i][j] = board[i][j];
            }
        }

        moveTiles(board, move);

        // Check if the board has changed
        int boardChanged = 0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] != prevBoard[i][j]) {
                    boardChanged = 1;
                    break;
                }
            }
            if (boardChanged) {
                break;
            }
        }

        // Add a new random tile only if the board has changed
        if (boardChanged) {
            addRandomTile(board);
        }


        // To-do-list: Game over conditions, score tracking 
    }

    return 0;
}