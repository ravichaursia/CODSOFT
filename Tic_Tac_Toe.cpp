#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + (i * 3 + j); // Fill with 1-9
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check for win
bool checkWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return true;

    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return true;

    return false;
}

// Function to check for draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Function to handle player move
bool makeMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;

    if (move < 1 || move > 9) {
        cout << "Invalid move! Try again.\n";
        return false;
    }

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Cell already taken! Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

// Main game loop
void playGame() {
    initializeBoard();
    currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        displayBoard();
        if (makeMove()) {
            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
    }
}

// Main function
int main() {
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}
