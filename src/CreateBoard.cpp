#include "head.h"

void CreateBoard(vector<vector<char>> &Board) {
    char Letter[9] = {' ', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    for (int lt = 0; lt < 9; ++lt) {
        Board[0][lt] = Letter[lt];
        Board[1][lt] = 'p';
        Board[6][lt] = 'p' - 32;
        Board[7][lt] = Letter[lt] - 32;
        for (int i = 2; i < 6; ++i)
            Board[i][lt] = ' ';
    }
    for (int i = 0; i < 8; ++i) {
        Board[i][0] = '8' - i;
        Board[8][i + 1] = 'a' + i;
    }
}

