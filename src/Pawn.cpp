#include "head.h"

extern void PrintBoard(vector<vector<char>> &Board);

void Pawn(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw) {
    if ((step[3] == '-' && ((((bw && step[2] == 50 && step[5] <= 52) ||
                              (!bw && step[2] == 55 && step[5] >= 53)) &&
                             ((!bw && step[2] == step[5] + 2) |
                              (bw && step[2] == step[5] - 2)) &&
                             Board[56 - step[5] - 1][step[4] % 96] == ' ') ||
                            ((!bw && step[2] == step[5] + 1) |
                             (bw && step[2] == step[5] - 1)))) |
        (step[3] == 'x' &&
         ((!bw && step[2] == step[5] + 1) | (bw && step[2] == step[5] - 1)))) {
        LogStep.push_back(step);
        bw = num & 1;
        ++num;
        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        PrintBoard(Board);
    }
}
