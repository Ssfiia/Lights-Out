#include <iostream>
#include <vector>
#include <fstream>
void change(std::vector<std::vector<int>>& board, int row, int col);
bool checkWin(const std::vector<std::vector<int>>& board);
bool saveGame(const std::vector<std::vector<int>>& board, int moves);
bool loadGame(std::vector<std::vector<int>>& board, int& moves); 
void newGame(std::vector<std::vector<int>>& board, int& moves);

