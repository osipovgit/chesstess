#include "head.h"

extern void CheckStep(vector<vector<char>> &Board, int &num, string &step, vector<string> &LogStep, bool &bw);
extern void CreateBoard(vector<vector<char>> &Board);
extern void PrintBoard(vector<vector<char>> &Board);

int main() {
    ios_base::sync_with_stdio(false);
    int num = 0, fin = -11;
    bool bw = true;
    string step;
    vector<vector<char>> Board(9, vector<char>(9));
    vector<string> LogStep(1);
    CreateBoard(Board);
    PrintBoard(Board);
    LogStep[0] = "Start game";
    while (1) {
        cin >> step;
        if (step[6] == '#')
            fin = num;
        CheckStep(Board, num, step, LogStep, bw);
        if (fin == num - 1) {
            if (bw)
                cout << endl << "~~~~~~~~~~~~~~~~~~\n  Победа черных!\n~~~~~~~~~~~~~~~~~~" << endl;
            else cout << endl << "~~~~~~~~~~~~~~~~~~\n  Победа белых!\n~~~~~~~~~~~~~~~~~~" << endl;
            break;
        } else fin = -11;
    }
}
