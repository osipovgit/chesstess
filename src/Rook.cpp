#include "head.h"

extern void PrintBoard(vector<vector<char>> &Board);

void Rook(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw) {
    int i1 = 0, i2 = 0, j;
    bool gg = false;
    if (step[2] != step[5]) {
        i1 = step[2];
        i2 = step[5];
        j = step[4];
    } else if (step[1] != step[4]) {
        i1 = step[1];
        i2 = step[4];
        j = step[5];
    }
    if (i1 < i2)
        --i2;
    else ++i2;
    gg += i1 != 0;
    while (i1 != i2) {
        if (i1 < i2)
            ++i1;
        else --i1;
        if (Board[56 - i1][j % 96] != ' ') {
            gg = false;
            break;
        }
    }
    if (gg) {
        LogStep.push_back(step);
        bw = num & 1;
        ++num;
        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        PrintBoard(Board);
    }
}
