#include "head.h"

bool Rook(vector<vector<char>> &Board, string &step) {
    int i1 = 0, i2 = 0, j;
    bool gg = false;
    if (step[2] != step[5]) {
        i1 = step[2];
        i2 = step[5];
        j = step[4];
    } else if (step[1] != step[4]) {
        i1 = step[1];
        i2 = step[4];
        j = step[5];
    }
    if (i1 < i2)
        --i2;
    else ++i2;
    gg += i1 != 0;
    while (i1 != i2) {
        if (i1 < i2)
            ++i1;
        else --i1;
        if (Board[56 - i1][j % 96] != ' ') {
            gg = false;
            break;
        }
    }
    if (gg) {
        Board[56 - step[5]][step[4] % 96] = Board[56 - step[2]][step[1] % 96];
        Board[56 - step[2]][step[1] % 96] = ' ';
        return true;
    }
    return false;
}


TEST_CASE("Rook", "Ladya") 
{
  vector<vector<char>> Board(9, vector<char>(9));
  string step;
  step = "Ra1-a2";
  REQUIRE(Rook(Board, step) == true);
  step = "Ra1-a3";
  REQUIRE(Rook(Board, step) == false);
  step = "Ra1-a4";
  REQUIRE(Rook(Board, step) == false);
  step = "Ra1-a5";
  REQUIRE(Rook(Board, step) == false);
  step = "Ra1-a6";
  REQUIRE(Rook(Board, step) == false);
  step = "Ra1-a7";
  REQUIRE(Rook(Board, step) == false);
  step = "Ra1-a8";
  REQUIRE(Rook(Board, step) == false);
  step = "Ra1-b1";
  REQUIRE(Rook(Board, step) == true);
  step = "Rh1-h2";
  REQUIRE(Rook(Board, step) == true);
  step = "Rh1-h3";
  REQUIRE(Rook(Board, step) == false);
  step = "Rh1-h4";
  REQUIRE(Rook(Board, step) == false);
  step = "Rh1-h5";
  REQUIRE(Rook(Board, step) == false);
  step = "Rh1-h6";
  REQUIRE(Rook(Board, step) == false);
  step = "Rh1-h7";
  REQUIRE(Rook(Board, step) == false);
  step = "Rh1-h8";
  REQUIRE(Rook(Board, step) == false);
  cout << "Test Rook" << endl;
}
