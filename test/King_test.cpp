#include "head.h"

bool King(vector<vector<char>> &Board, string &step, bool bw) {
    int a = abs(step[4] - step[1]), b = abs(step[5] - step[2]);
    if (a <= 1 && b <= 1) {

        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        return true;
    }
   return false;
}

TEST_CASE("King", "Korol") {
  vector<vector<char>> Board(9, vector<char>(9));
  string step;
  step = "Ke1-e4";
  REQUIRE(King(Board, step, true) == false);
  step = "Ke8-e2";
  REQUIRE(King(Board, step, false) == false);
  step = "Ke1-e2";
  REQUIRE(King(Board, step, true) == true);
  step = "Ke8-d8";
  REQUIRE(King(Board, step, false) == true);
  step = "Ke1-d1";
  REQUIRE(King(Board, step, true) == true);
  step = "Ke8-e7";
  REQUIRE(King(Board, step, false) == true);
  step = "Ke1-d2";
  REQUIRE(King(Board, step, true) == true);
  step = "Ke8-d7";
  REQUIRE(King(Board, step, false) == true);
  step = "Be1-g3";
  REQUIRE(King(Board, step, true) == false);
  step = "Be8-c6";
  REQUIRE(King(Board, step, false) == false);
  cout << "Test King" << endl;
}
