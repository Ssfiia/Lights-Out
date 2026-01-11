#include <iostream>
#include <vector>
#include <Windows.h>
#include "Header.h"

void displayMenu() {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "\n   ÃÀÑÈÌ ÑÂÅÒ \n";
    cout << "1. Íîâàÿ èãðà\n";
    cout << "2. Çàãðóçèòü èãðó\n";
    cout << "3. Ñïðàâêà\n";
    cout << "0. Âûõîä\n";
    cout << "Âûáåðèòå: ";
}

void display(const std::vector<std::vector<int>>& board, int moves) {
    using namespace std;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int size = board.size();

    cout << "Õîäîâ: " << moves << "\n";
    cout << "1 - ñâåò âêëþ÷åí, 0 - ñâåò âûêëþ÷åí\n\n";
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
    cout << "    ÑÏÐÀÂÊÀ \n";
    cout << "  ÏÐÀÂÈËÀ ÈÃÐÛ:\n";
    cout << "1. Èãðîâîå ïîëå ñîñòîèò èç êëåòîê\n";
    cout << "2. 1 îçíà÷àåò, ÷òî ñâåò âêëþ÷åí\n";
    cout << "3. 0 îçíà÷àåò, ÷òî ñâåò âûêëþ÷åí\n";
    cout << "4. Ïðè íàæàòèè íà êëåòêó ìåíÿåòñÿ åå ñîñòîÿíèå\n";
    cout << "   è ñîñòîÿíèå ñîñåäíèõ êëåòîê (ñâåðõó, ñíèçó, ñëåâà, ñïðàâà)\n";
    cout << "5. Öåëü: âûêëþ÷èòü âñå îãíè (ñäåëàòü âñå êëåòêè 0)\n\n";

    cout << "  ÓÏÐÀÂËÅÍÈÅ:\n";
    cout << "- Ââîäèòå äâà ÷èñëà: íîìåð ñòðîêè è íîìåð ñòîëáöà\n";
    cout << "- Íàïðèìåð: 2 3 - íàæàòü êëåòêó âî 2-é ñòðîêå, 3-ì ñòîëáöå\n";
    cout << "- 0 0 - ñîõðàíèòü èãðó è âûéòè â ìåíþ\n\n";

    cout << "ÏÐÈÌÅÐ ÏÎËß 3x3:\n";
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
            else cout << "Ñîõðàí¸ííûõ èãð íåò.";
            break;
        }
        case 3:
            showHelp();
            continue;
        case 0:
            cout << "Äî ñâèäàíèÿ!\n";
            return 0;
        default:
            cout << "Íåâåðíûé âûáîð! Ïîïðîáóéòå ñíîâà.\n";
            continue;
        }
        while (gameLoaded) {
            display(board, moves);

            if (checkWin(board)) {
                cout << "ÏÎÇÄÐÀÂËßÅÌ! ÂÛ ÂÛÈÃÐÀËÈ! \n";
                cout << "Âñåãî õîäîâ: " << moves << "\n";
                break;
            }
            cout << "Ââåäèòå ñòðîêó è ñòîëáåö (íàïðèìåð: 2 3)\n Èëè 0 0 äëÿ ñîõðàíåíèÿ è âûõîäà: ";
            int row, col;
            cin >> row >> col;
            if (row == 0 && col == 0) {
                saveGame(board, moves);
                break;
            }
            int size = board.size();
            if (row < 1 || row > size || col < 1 || col > size) {
                cout << "Îøèáêà! Ââåäèòå ÷èñëà îò 1 äî " << size << "\n";
                continue;
            }
            change(board, row - 1, col - 1);
            moves++;
        }
    }
}
