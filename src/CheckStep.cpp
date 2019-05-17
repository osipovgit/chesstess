#include "head.h"

extern void King(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);
extern void Rook(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);
extern void kNight(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);
extern void Bishop(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);
extern void Queen(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);
extern void Pawn(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);

void CheckStep(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw) {
    set<char> prnbqk{'P', 'R', 'N', 'B', 'Q', 'K'};
    set<char> ah{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '1', '2', '3', '4', '5', '6', '7', '8'};
    if (step == "gitlog")
        for (auto &i : LogStep)
            cout << i << endl;
    if (prnbqk.count(step[0]) & ah.count(step[2]) & ah.count(step[5]) & ah.count(step[1]) & ah.count(step[4]) &
        (step[1] != step[4] || step[2] != step[5]) & ((step[3] == 'x' && Board[56 - step[5]][step[4] % 96] != ' ' && tolower(Board[56 - step[5]][step[4] % 96]) != 'k' &&
                                                      ((bw && Board[56 - step[5]][step[4] % 96] ==
                                                              tolower(Board[56 - step[5]][step[4] % 96])) |
                                                       (!bw && Board[56 - step[5]][step[4] % 96] ==
                                                               toupper(Board[56 - step[5]][step[4] % 96])))) |
                                                     (step[3] == '-' && Board[56 - step[5]][step[4] % 96] == ' '))) {
        if (step[0] == 'P' && (step[1] == step[4] && step[3] == '-') |
                              (step[3] == 'x' && (step[1] == step[4] - 1) | (step[1] == step[4] + 1)) &&
            (bw && Board[56 - step[2]][step[1] % 96] == 'P') | (!bw && Board[56 - step[2]][step[1] % 96] == 'p'))
            Pawn(Board, num, step, LogStep, bw);

        if (step[0] == 'R' && ((bw && Board[56 - step[2]][step[1] % 96] == 'R') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'r')) &&
            (step[1] == step[4] || step[2] == step[5]))
            Rook(Board, num, step, LogStep, bw);

        if (step[0] == 'B' && ((bw && Board[56 - step[2]][step[1] % 96] == 'B') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'b')))
            Bishop(Board, num, step, LogStep, bw);
   
        if (step[0] == 'N' && ((bw && Board[56 - step[2]][step[1] % 96] == 'N') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'n')) &&
            (step[1] != step[4] && step[2] != step[5]))
            kNight(Board, num, step, LogStep, bw);
        if (step[0] == 'K' && ((bw && Board[56 - step[2]][step[1] % 96] == 'K') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'k')))
            King(Board, num, step, LogStep, bw);
        if (step[0] == 'Q' && ((bw && Board[56 - step[2]][step[1] % 96] == 'Q') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'q')))
            Queen(Board, num, step, LogStep, bw);
    }
}
