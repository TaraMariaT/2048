Simple version of game 2048

Game runs in terminal and here's a brief explanation of how it works:

Game start:

This version has 4x4 game board. Game starts by adding two random tiles with values of 2 or 4.

Game Loop:

The main game loop continues until there are no more valid moves.
The current state of the board and the player's score are displayed.
The player is prompted to enter a move (w/a/s/d for up/left/down/right).
After the move, a check is performed to see if the board has changed. If it has, a new random tile is added, and the player's score is updated based on merged tiles.

User Input and Movement:

The player's move is taken as input using scanf.
The moveTiles function then handles the movement logic.
The tiles slide in the specified direction, and adjacent tiles with the same value are merged.

Score Tracking:

The player's score is tracked throughout the game.
The score is updated each time two tiles are merged. The score is displayed along with the game board.

Game Over Check:

Game checks if there are any empty cells on the board or if any adjacent tiles have the same value. If neither condition is met, the game is over.

Final Display:

After the game is over, the final state of the board and the player's score are displayed.

Overall, this code provides a basic implementation of the 2048 game in C, allowing the player to make moves, merge tiles, and accumulate a score until there are no more valid moves.
