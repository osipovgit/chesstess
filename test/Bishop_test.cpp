#include "head.h"

int Bishop(vector<vector<char>> &Board, string &step, bool bw) {
    if (abs(step[1] - step[4]) == abs(step[2] - step[5])) {
        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        return 1;
    }
    return 0;
}

TEST_CASE("Bishop", "SLON") {
  vector<vector<char>> Board(9, vector<char>(9));
  string step;
  step = "Bc1-c4";
  REQUIRE(Bishop(Board, step, true) == 0);
  step = "Bc1-e1";
  REQUIRE(Bishop(Board, step, false) == 0);
  step = "Bc1-e3";
  REQUIRE(Bishop(Board, step, true) == 1);
  step = "Bc8-e6";
  REQUIRE(Bishop(Board, step, false) == 1);
  step = "Bc1-a3";
  REQUIRE(Bishop(Board, step, true) == 1);
  step = "Bc8-a6";
  REQUIRE(Bishop(Board, step, false) == 1);
  step = "Bf1-f4";
  REQUIRE(Bishop(Board, step, true) == 0);
  step = "Bf1-e1";
  REQUIRE(Bishop(Board, step, false) == 0);
  step = "Bf1-d3";
  REQUIRE(Bishop(Board, step, true) == 1);
  step = "Bf8-d6";
  REQUIRE(Bishop(Board, step, false) == 1);
  step = "Bf1-h3";
  REQUIRE(Bishop(Board, step, true) == 1);
  step = "Bf8-h6";
  REQUIRE(Bishop(Board, step, false) == 1);
  cout << "Test Bishop" << endl;
}
