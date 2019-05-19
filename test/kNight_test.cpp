#include "head.h"

bool kNight(vector<vector<char>> &Board, string &step) {
    int a = abs(step[4] - step[1]), b = abs(step[5] - step[2]);
    if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        return true;
    }
    return false;
}

TEST_CASE("kNight", "Kon'") {
  vector<vector<char>> Board(9, vector<char>(9));
  string step;
  step = "Nb1-b3";
  REQUIRE(kNight(Board, step) == false);
  step = "Ng1-g3";
  REQUIRE(kNight(Board, step) == false);
  step = "Nb1-d3";
  REQUIRE(kNight(Board, step) == false);
  step = "Ng1-e1";
  REQUIRE(kNight(Board, step) == false);
  step = "Nb1-a3";
  REQUIRE(kNight(Board, step) == true);
  step = "Ng1-f3";
  REQUIRE(kNight(Board, step) == true);
  step = "Nb1-c3";
  REQUIRE(kNight(Board, step) == true);
  step = "Ng1-h3";
  REQUIRE(kNight(Board, step) == true);
  step = "Nb1-d2";
  REQUIRE(kNight(Board, step) == true);
  step = "Ng1-e2";
  REQUIRE(kNight(Board, step) == true);
  step = "Nb8-a6";
  REQUIRE(kNight(Board, step) == true);
  step = "Ng8-f6";
  REQUIRE(kNight(Board, step) == true);
  step = "Nb8-c6";
  REQUIRE(kNight(Board, step) == true);
  step = "Ng8-h6";
  REQUIRE(kNight(Board, step) == true);
  step = "Nb8-d7";
  REQUIRE(kNight(Board, step) == true);
  step = "Ng8-e7";
  REQUIRE(kNight(Board, step) == true);
  cout << "Test kNight" << endl;
}
