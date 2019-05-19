#include "head.h"

int CheckStep(vector<vector<char>> &Board, string &step, bool bw) {
    set<char> prnbqk{'P', 'R', 'N', 'B', 'Q', 'K'};
    set<char> ah{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', '1', '2', '3', '4', '5', '6', '7', '8'};
    if (prnbqk.count(step[0]) & ah.count(step[2]) & ah.count(step[5]) & ah.count(step[1]) & ah.count(step[4]) &
        (step[1] != step[4] | step[2] != step[5]) & ((step[3] == 'x' && Board[56 - step[5]][step[4] % 96] != ' ' &&
                                                      tolower(Board[56 - step[5]][step[4] % 96]) != 'k' &&
                                                      ((bw && Board[56 - step[5]][step[4] % 96] ==
                                                              tolower(Board[56 - step[5]][step[4] % 96])) |
                                                       (!bw && Board[56 - step[5]][step[4] % 96] ==
                                                               toupper(Board[56 - step[5]][step[4] % 96])))) |
                                                     (step[3] == '-' && Board[56 - step[5]][step[4] % 96] == ' '))) {
        if (step[0] == 'P' && (step[1] == step[4] && step[3] == '-') |
                              (step[3] == 'x' && (step[1] == step[4] - 1) | (step[1] == step[4] + 1)) &&
            (bw && Board[56 - step[2]][step[1] % 96] == 'P') | (!bw && Board[56 - step[2]][step[1] % 96] == 'p'))
            return 1;

        if (step[0] == 'R' && ((bw && Board[56 - step[2]][step[1] % 96] == 'R') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'r')) &&
            (step[1] == step[4] || step[2] == step[5]))
            return 2;

        if (step[0] == 'B' && ((bw && Board[56 - step[2]][step[1] % 96] == 'B') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'b')))
            return 3;

        if (step[0] == 'N' && ((bw && Board[56 - step[2]][step[1] % 96] == 'N') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'n')) &&
            (step[1] != step[4] && step[2] != step[5]))
            return 4;
;
        if (step[0] == 'K' && ((bw && Board[56 - step[2]][step[1] % 96] == 'K') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'k')))
            return 5;

        if (step[0] == 'Q' && ((bw && Board[56 - step[2]][step[1] % 96] == 'Q') |
                               (!bw && Board[56 - step[2]][step[1] % 96] == 'q')))
            return 6;
    }
    return 0;
}

TEST_CASE("CheckStep", "top-top?") {
  vector<vector<char>> Board(9, vector<char>(9));
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
  string step;
  step = "Pe2-e9";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ra8-a0";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Pe2-e2";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ra8-a8";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ae2-e3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "pe7-e1";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "4e2-e5";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "rghfkg";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Pe3-e5";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Pe6-e5";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Pe2-e3";
  REQUIRE(CheckStep(Board, step, true) == 1);
  step = "Pe7-e6";
  REQUIRE(CheckStep(Board, step, false) == 1);
  step = "Pe2-e4";
  REQUIRE(CheckStep(Board, step, true) == 1);
  step = "Pe7-e5";
  REQUIRE(CheckStep(Board, step, false) == 1);
  step = "Pe2-e7";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Pe7-e1";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Pe2-e1";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Pe7-e8";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Pe2-d4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Pe7-f5";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Pe2xe3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Pe7xe4";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Pe2xd3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Pe7xd6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Pe2xf3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Pe7xf6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ra1-a3";
  REQUIRE(CheckStep(Board, step, true) == 2);
  step = "Ra8-a5";
  REQUIRE(CheckStep(Board, step, false) == 2);
  step = "Rh1-h5";
  REQUIRE(CheckStep(Board, step, true) == 2);
  step = "Rh8-h4";
  REQUIRE(CheckStep(Board, step, false) == 2);
  step = "Ra1-a3";
  REQUIRE(CheckStep(Board, step, true) == 2);
  step = "Ra8-a5";
  REQUIRE(CheckStep(Board, step, false) == 2);
  step = "Ra2-a4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Rf8-a5";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ra1xa3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ra8xa5";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Rh1xh5";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Rh8xh4";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ra1xa3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ra8xa5";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ra2xa4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Rf8xa5";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Bc1-a3";
  REQUIRE(CheckStep(Board, step, true) == 3);
  step = "Bc8-a6";
  REQUIRE(CheckStep(Board, step, false) == 3);
  step = "Bf1-d3";
  REQUIRE(CheckStep(Board, step, true) == 3);
  step = "Bf8-d6";
  REQUIRE(CheckStep(Board, step, false) == 3);
  step = "Bc1-f4";
  REQUIRE(CheckStep(Board, step, true) == 3);
  step = "Bc8-g5";
  REQUIRE(CheckStep(Board, step, false) == 3);
  step = "Bf2-f4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Bc1xa3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Bc8xa6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Bf1xd3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Bf8xd6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Bc1xf4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Bc8xg5";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Bf2xf4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Nb1-a3";
  REQUIRE(CheckStep(Board, step, true) == 4);
  step = "Ng1-f3";
  REQUIRE(CheckStep(Board, step, true) == 4);
  step = "Nb1-c3";
  REQUIRE(CheckStep(Board, step, true) == 4);
  step = "Ng1-h3";
  REQUIRE(CheckStep(Board, step, true) == 4);
  step = "Nb1xd2";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ng1xe2";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Nb8-a6";
  REQUIRE(CheckStep(Board, step, false) == 4);
  step = "Ng8-f6";
  REQUIRE(CheckStep(Board, step, false) == 4);
  step = "Nb8-c6";
  REQUIRE(CheckStep(Board, step, false) == 4);
  step = "Ng8-h6";
  REQUIRE(CheckStep(Board, step, false) == 4);
  step = "Nb8xd7";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ng8xe7";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Nb8xa6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ng8xf6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Nb8xc6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ng8xh6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Nb1xa3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ng1xf3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Nb1xc3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ng1xh3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ke1xe4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ke8xe3";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ke1xe2";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ke8xd8";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ke1xd1";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ke8xe7";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Ke1xd2";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Ke8xd7";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Be1xg3";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Be8xc6";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Qd1-d4";
  REQUIRE(CheckStep(Board, step, true) == 6);
  step = "Qd8-d4";
  REQUIRE(CheckStep(Board, step, false) == 6);
  step = "Qd1-g4";
  REQUIRE(CheckStep(Board, step, true) == 6);
  step = "Qd8-g4";
  REQUIRE(CheckStep(Board, step, false) == 6);
  step = "Qd1-a4";
  REQUIRE(CheckStep(Board, step, true) == 6);
  step = "Qd8-a4";
  REQUIRE(CheckStep(Board, step, false) == 6);
  step = "Qd1xd4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Qd8xd4";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Qd1xg4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Qd8xg4";
  REQUIRE(CheckStep(Board, step, false) == 0);
  step = "Qd1xa4";
  REQUIRE(CheckStep(Board, step, true) == 0);
  step = "Qd8xa4";
  REQUIRE(CheckStep(Board, step, false) == 0);
  cout << "Test CheckStep" << endl;
}
