#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if the current player has won
int checkWinner() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    
    return 0;
}

// Function to check if the board is full (for a draw)
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Function to switch players
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

// Function to play the game
void playGame() {
    int row, col;
    while (1) {
        printBoard();
        printf("Player %c, enter row and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        // Validate the input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move, try again.\n");
            continue;
        }
        
        // Make the move
        board[row][col] = currentPlayer;

        // Check for a winner
        if (checkWinner()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        // Check for a draw
        if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // Switch players
        switchPlayer();
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}
