#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

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
    // Moving tiles logic here
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

        // Move tiles based on user input
        moveTiles(board, move);

        // Add a new random tile to the board
        addRandomTile(board);

        // To-do-list: Game over conditions, score tracking 
    }

    return 0;
}