#include <iostream>
#include <vector>
#include <fstream>
#include "Header.h"
const std::string savef = "game_save.txt";
bool saveGame(const std::vector<std::vector<int>>& board, int moves) {
    using namespace std;
    ofstream file(savef);
    if (!file.is_open()) {
        cout << "Ошибка сохранения!\n";
        return false;
    }
    int size = board.size();
    file << size << " " << moves << "\n";
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            file << board[i][j] << " ";
        }
        file << "\n";
    }
    file.close();
    cout << "Игра сохранена!\n";
    return true;
}

bool loadGame(std::vector<std::vector<int>>& board, int& moves) {
    using namespace std;
    ifstream file(savef);
    if (!file.is_open() || file.peek() == EOF) {
        cout << "Сохраненная игра не найдена!\n";
        return false;
    }
    int size;
    file >> size >> moves;
    board.resize(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> board[i][j];
        }
    }
    file.close();
    cout << "Игра загружена!\n";
    return true;
}