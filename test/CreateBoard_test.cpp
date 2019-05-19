#include "head.h"

char CreateBoard(vector<vector<char>> &Board, int a) {
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
    return Board[a][4];
}

TEST_CASE("CreateBoard", "Create") {
  vector<vector<char>> Board(9, vector<char>(9));
  REQUIRE(CreateBoard(Board, 0) == 'q');
  REQUIRE(CreateBoard(Board, 1) == 'p');
  REQUIRE(CreateBoard(Board, 4) == ' ');
  REQUIRE(CreateBoard(Board, 6) == 'P');
  REQUIRE(CreateBoard(Board, 7) == 'Q');
  REQUIRE(CreateBoard(Board, 8) == 'd');
  cout << "Test CreateBoard" << endl;
}
