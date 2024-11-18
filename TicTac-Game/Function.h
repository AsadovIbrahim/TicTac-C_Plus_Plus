#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>

void displayBoard(const std::vector<std::vector<char>>& board);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool checkDraw(const std::vector<std::vector<char>>& board);
void computerMove(std::vector<std::vector<char>>& board);
void playerMove(std::vector<std::vector<char>>& board);

#endif 
