#include "Function.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << endl;
    cout << endl;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == '-') return false;
        }
    }
    return true;
}

void computerMove(vector<vector<char>>& board) {
    srand(time(0));
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != '-');
    board[row][col] = 'O';
}

void playerMove(vector<vector<char>>& board) {
    int row, col;
    do {
        cout << "Enter your move (row and column: 1-3): ";
        cin >> row >> col;
        --row; --col;
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
            cout << "Invalid move. Try again.\n";
        }
        else {
            break;
        }
    } while (true);
    board[row][col] = 'X';
}
