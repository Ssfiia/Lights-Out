#include <iostream>
#include <vector>
#include <Windows.h>
#include "Header.h"

void displayMenu() {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "\n   ГАСИМ СВЕТ \n";
    cout << "1. Новая игра\n";
    cout << "2. Загрузить игру\n";
    cout << "3. Справка\n";
    cout << "0. Выход\n";
    cout << "Выберите: ";
}

void display(const std::vector<std::vector<int>>& board, int moves) {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int size = board.size();

    cout << "Ходов: " << moves << "\n";
    cout << "1 - свет включен, 0 - свет выключен\n\n";
    cout << "   ";
    for (int j = 0; j < size; j++) {
        cout << " " << j + 1 << "  ";
    }
    cout << "\n";
    cout << "  +";
    for (int j = 0; j < size; j++) {
        cout << "---+";
    }
    cout << "\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " |";
        for (int j = 0; j < size; j++) {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n";
        cout << "  +";
        for (int j = 0; j < size; j++) {
            cout << "---+";
        }
        cout << "\n";
    }
    cout << "\n";
}

void showHelp() {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "    СПРАВКА \n";
    cout << "  ПРАВИЛА ИГРЫ:\n";
    cout << "1. Игровое поле состоит из клеток\n";
    cout << "2. 1 означает, что свет включен\n";
    cout << "3. 0 означает, что свет выключен\n";
    cout << "4. При нажатии на клетку меняется ее состояние\n";
    cout << "   и состояние соседних клеток (сверху, снизу, слева, справа)\n";
    cout << "5. Цель: выключить все огни (сделать все клетки 0)\n\n";

    cout << "  УПРАВЛЕНИЕ:\n";
    cout << "- Вводите два числа: номер строки и номер столбца\n";
    cout << "- Например: 2 3 - нажать клетку во 2-й строке, 3-м столбце\n";
    cout << "- 0 0 - сохранить игру и выйти в меню\n\n";

    cout << "ПРИМЕР ПОЛЯ 3x3:\n";
    cout << "   1   2   3  \n";
    cout << "  +---+---+---+\n";
    cout << "1 | 1 | 0 | 1 |\n";
    cout << "  +---+---+---+\n";
    cout << "2 | 0 | 1 | 0 |\n";
    cout << "  +---+---+---+\n";
    cout << "3 | 1 | 1 | 0 |\n";
    cout << "  +---+---+---+\n";
}

int main() {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<vector<int>> board;
    int moves = 0;
    bool gameLoaded = false;
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            newGame(board, moves);
            gameLoaded = true;
            break;
        }
        case 2: {
            if (loadGame(board, moves)) gameLoaded = true;
            else cout << "Сохранённых игр нет.";
            break;
        }
        case 3:
            showHelp();
            continue;
        case 0:
            cout << "До свидания!\n";
            return 0;
        default:
            cout << "Неверный выбор! Попробуйте снова.\n";
            continue;
        }
        while (gameLoaded) {
            display(board, moves);

            if (checkWin(board)) {
                cout << "ПОЗДРАВЛЯЕМ! ВЫ ВЫИГРАЛИ! \n";
                cout << "Всего ходов: " << moves << "\n";
                break;
            }
            cout << "Введите строку и столбец (например: 2 3)\n Или 0 0 для сохранения и выхода: ";
            int row, col;
            cin >> row >> col;
            if (row == 0 && col == 0) {
                saveGame(board, moves);
                break;
            }
            int size = board.size();
            if (row < 1 || row > size || col < 1 || col > size) {
                cout << "Ошибка! Введите числа от 1 до " << size << "\n";
                continue;
            }
            change(board, row - 1, col - 1);
            moves++;
        }
    }
}
