#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Header.h"

void change(std::vector<std::vector<int>>& board, int row, int col) {
    int size = board.size();
    board[row][col] = !board[row][col];
    if (row > 0) board[row - 1][col] = !board[row - 1][col];
    if (row < size - 1) board[row + 1][col] = !board[row + 1][col];
    if (col > 0) board[row][col - 1] = !board[row][col - 1];
    if (col < size - 1) board[row][col + 1] = !board[row][col + 1];
}
bool checkWin(const std::vector<std::vector<int>>& board) {
    bool f = true;
    int size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 1) f = false;
        }
    }
    return f;
}

void newGame(std::vector<std::vector<int>>& board, int& moves) {
    using namespace std;
    int size;
    cout << "Введите размер поля (2-9): ";
    cin >> size;
    while (size < 2 || size > 9) {
        cout << "Введён некорректный размер поля.\n Введите корректно (2-9):";
        cin >> size;
    }
    board.clear();
    board.resize(size, vector<int>(size, 0));
    moves = 0;
    srand(time(0));
    int clicks = size * 3;
    for (int k = 0; k < clicks; k++) {
        int i = rand() % size;
        int j = rand() % size;
        change(board, i, j);
    }
    cout << "Новая игра создана! Размер поля: " << size << "x" << size << "\n";
}