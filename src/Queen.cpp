#include "head.h"

extern void Rook(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);
extern void Bishop(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);

void Queen(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw) {
    if (step[1] == step[4] || step[2] == step[5])
        Rook(Board, num, step, LogStep, bw);
    else Bishop(Board, num, step, LogStep, bw);
}

