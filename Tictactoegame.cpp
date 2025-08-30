#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board
char currentPlayer; // 'X' or 'O'

// Function to reset the board
void resetBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
    currentPlayer = 'X'; // X starts first
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
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check if the move is valid
bool isValidMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

// Function to make a move
void makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = currentPlayer;
}

// Function to check for a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

// Function to check for draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main game loop
int main() {
    char playAgain;

    do {
        resetBoard();
        bool gameOver = false;

        cout << "Welcome to Tic-Tac-Toe!" << endl;

        while (!gameOver) {
            displayBoard();
            int choice;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            if (choice >= 1 && choice <= 9 && isValidMove(choice)) {
                makeMove(choice);

                if (checkWin()) {
                    displayBoard();
                    cout << "🎉 Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move! Try again." << endl;
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}
