#include "head.h"

extern void PrintBoard(vector<vector<char>> &Board);

void Bishop(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw) {
    if (abs(step[1] - step[4]) == abs(step[2] - step[5])) {
        LogStep.push_back(step);
        bw = num & 1;
        ++num;
        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        PrintBoard(Board);
    }
}
