#include <stdio.h>

char board[3][3];  // Tic-Tac-Toe board
char currentPlayer = 'X';  // Current player ('X' or 'O')

// Function to initialize the board
void initializeBoard() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    int i, j;
    printf("\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if a player has won
int checkWinner() {
    int i;
    // Check rows
    for(i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    // Check columns
    for(i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

// Function to check if the board is full (draw condition)
int isBoardFull() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to take player input and update the board
void playerMove() {
    int row, col;
    printf("Player %c, enter row and column (0, 1, 2): ", currentPlayer);
    while(1) {
        scanf("%d %d", &row, &col);
        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break;
        } else {
            printf("Invalid move! Try again: ");
        }
    }
}

// Function to switch players
void switchPlayer() {
    if(currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int main() {
    int gameOver = 0;
    initializeBoard();

    while(!gameOver) {
        displayBoard();
        playerMove();
        
        // Check for a winner
        if(checkWinner()) {
            displayBoard();
            printf("Player %c wins!\n", currentPlayer);
            gameOver = 1;
        } else if(isBoardFull()) {
            displayBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            switchPlayer();
        }
    }
    return 0;
}
