#include "head.h"

extern void PrintBoard(vector<vector<char>> &Board);

void King(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw) {
    int a = abs(step[4] - step[1]), b = abs(step[5] - step[2]);
    if (a <= 1 && b <= 1) {
        LogStep.push_back(step);
        bw = num & 1;
        ++num;
        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        PrintBoard(Board);
    }
}

