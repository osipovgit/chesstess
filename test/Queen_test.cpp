#include "head.h"

int Queen(vector<vector<char>> &Board, string &step) {
    if (step[1] == step[4] || step[2] == step[5])
        return 0;
    else return 1;
}
TEST_CASE("Queen", "KorolVEA") {
  vector<vector<char>> Board(9, vector<char>(9));
  string step;
  step = "Qd1-d4";
  REQUIRE(Queen(Board, step) == 0);
  step = "Qd8-d4";
  REQUIRE(Queen(Board, step) == 0);
  step = "Qd1-g4";
  REQUIRE(Queen(Board, step) == 1);
  step = "Qd8-g4";
  REQUIRE(Queen(Board, step) == 1);
  step = "Qd1-a4";
  REQUIRE(Queen(Board, step) == 1);
  step = "Qd8-a4";
  REQUIRE(Queen(Board, step) == 1);
  cout << "Test Queen" << endl;
}
