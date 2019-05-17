#include "head.h"

void PrintBoard(vector<vector<char>> &Board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            if (i == 8 && j == 0)
                cout << "   ";
            else
                cout << Board[i][j] << "  ";
        cout << endl;
    }
}
