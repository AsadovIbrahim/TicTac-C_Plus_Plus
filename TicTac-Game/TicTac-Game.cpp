#include <iostream>
#include <vector>
#include "Function.h"

using namespace std;

int main() {
    vector<vector<char>> board = {
         {'-', '-', '-'},
         {'-', '-', '-'},
         {'-', '-', '-'}
    };

    displayBoard(board);
    while (true) {
        playerMove(board);
        displayBoard(board);
        if (checkWin(board, 'X')) {
            cout << "Congratulations! You win!\n";
            break;
        }
        if (checkDraw(board)) {
            cout << "It's a draw!\n";
            break;
        }
        computerMove(board);
        displayBoard(board);
        if (checkWin(board, 'O')) {
            cout << "Computer wins! Better luck next time.\n";
            break;
        }
        if (checkDraw(board)) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
