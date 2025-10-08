#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << endl;
    cout << "Current Board:" << endl;
    cout << endl;
    cout << " 1   2   3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---+---+---" << endl;
    }
    cout << endl;
}

bool checkWin(char board[3][3], char player) {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

    // Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool boardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3];
    char player = 'X';
    int row, col;

    // Initialize board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    cout << "=== TIC TAC TOE ===" << endl;
    cout << "Player 1: X, Player 2: O" << endl;
    cout << "Enter row and column (1-3) for your move." << endl;

    while (true) {
        displayBoard(board);

        cout << "Player " << player << ", enter row and column (1-3): ";

        //non-integer input handling - robustness
        if (!(cin >> row >> col)) {
            cout << "Invalid input! Please enter numbers only." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position! Please enter values between 1 and 3." << endl;
            continue;
        }

        if (board[row][col] != ' ') {
            cout << "Position already taken! Try again." << endl;
            continue;
        }

        board[row][col] = player;

        if (checkWin(board, player)) {
            displayBoard(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (boardFull(board)) {
            displayBoard(board);
            cout << "Game drawn!" << endl;
            break;
        }

        // Switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    cout << "Game over." << endl;
    return 0;
}
