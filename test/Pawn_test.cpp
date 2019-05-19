#include "head.h"

bool Pawn(vector<vector<char>> &Board, string &step, bool bw) {
    if ((step[3] == '-' && ((((bw && step[2] == 50 & step[5] <= 52) ||
                              (!bw && step[2] == 55 & step[5] >= 53)) &&
                             ((!bw && step[2] == step[5] + 2) |
                              (bw && step[2] == step[5] - 2))) ||
                            ((!bw && step[2] == step[5] + 1) |
                             (bw && step[2] == step[5] - 1)))) |
        (step[3] == 'x' &&
         ((!bw && step[2] == step[5] + 1) | (bw && step[2] == step[5] - 1)))) {
        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        return true;
    }
    return false;
}

TEST_CASE("Pawn", "Peshka") {
  vector<vector<char>> Board(9, vector<char>(9));
  string step;
  step = "Pa2-a3";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pa2-a4";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pb2-b3";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pb2-b4";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pc2-c3";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pc2-c4";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pd2-d3";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pd2-d4";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pe2-e3";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pe2-e4";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pf2-f3";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pf2-f4";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pg2-g3";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pg2-g4";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Ph2-h3";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Ph2-h4";
  REQUIRE(Pawn(Board, step, true) == true);
  step = "Pa7-a6";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pa7-a5";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pb7-b6";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pb7-b5";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pc7-c6";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pc7-c5";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pd7-d6";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pd7-d5";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pe7-e6";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pe7-e5";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pf7-f6";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pf7-f5";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pg7-g6";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pg7-g5";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Ph7-h6";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Ph7-h5";
  REQUIRE(Pawn(Board, step, false) == true);
  step = "Pa2-a1";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pa2-a5";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "P7-b6";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pb2-b5";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pc2-c1";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pc2-c5";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pd2-d1";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pd2-d5";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pe2-a5";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pe2-a6";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pf2-c7";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pf2-c6";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pg2-b5";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pg2-b2";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Ph2-f7";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Ph2-f5";
  REQUIRE(Pawn(Board, step, true) == false);
  step = "Pa2-a3";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pa6-a7";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pb8-b3";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pb4-b4";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pc7-c8";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pc7-c3";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pd7-d4";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pd7-d1";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pe7-e8";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pe7-a4";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pf8-b4";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pf7-c4";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pg7-d7";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Pg7-e3";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Ph7-f2";
  REQUIRE(Pawn(Board, step, false) == false);
  step = "Ph7-g2";
  REQUIRE(Pawn(Board, step, false) == false);
  cout << "Test Pawn" << endl;
}
