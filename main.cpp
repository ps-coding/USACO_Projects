#include <fstream>
#include <ostream>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[]) {
  char board[3][3];

  ifstream file("tttt.in");

  file >> board[0][0] >> board[0][1] >> board[0][2] >> board[1][0] >>
      board[1][1] >> board[1][2] >> board[2][0] >> board[2][1] >> board[2][2];

  unordered_set<char> individualWinners;
  unordered_set<string> groupWinners;

  // Check rows
  for (int i = 0; i < 3; i++) {
    char possibleWinner = board[i][0];
    char secondPossibleWinner = 0;

    for (int j = 1; j < 3; j++) {
      if (board[i][j] != possibleWinner &&
          board[i][j] != secondPossibleWinner) {
        if (secondPossibleWinner != 0) {
          possibleWinner = 0;
          secondPossibleWinner = 0;
          break;
        } else {
          secondPossibleWinner = board[i][j];
        }
      }
    }

    if (secondPossibleWinner != 0) {
      if (possibleWinner < secondPossibleWinner) {
        groupWinners.insert(string() + possibleWinner + secondPossibleWinner);
      } else {
        groupWinners.insert(string() + possibleWinner + secondPossibleWinner);
      }
    } else if (possibleWinner != 0) {
      individualWinners.insert(possibleWinner);
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++) {
    char possibleWinner = board[0][j];
    char secondPossibleWinner = 0;

    for (int i = 1; i < 3; i++) {
      if (board[i][j] != possibleWinner &&
          board[i][j] != secondPossibleWinner) {
        if (secondPossibleWinner != 0) {
          possibleWinner = 0;
          secondPossibleWinner = 0;
          break;
        } else {
          secondPossibleWinner = board[i][j];
        }
      }
    }

    if (secondPossibleWinner != 0) {
      if (possibleWinner < secondPossibleWinner) {
        groupWinners.insert(string() + possibleWinner + secondPossibleWinner);
      } else {
        groupWinners.insert(string() + possibleWinner + secondPossibleWinner);
      }
    } else if (possibleWinner != 0) {
      individualWinners.insert(possibleWinner);
    }
  }

  // Check diagonals
  {
    char possibleWinner = board[0][0];
    char secondPossibleWinner = 0;

    for (int i = 0; i < 3; i++) {
      if (board[i][i] != possibleWinner &&
          board[i][i] != secondPossibleWinner) {
        if (secondPossibleWinner != 0) {
          possibleWinner = 0;
          secondPossibleWinner = 0;
          break;
        } else {
          secondPossibleWinner = board[i][i];
        }
      }
    }

    if (secondPossibleWinner != 0) {
      if (possibleWinner < secondPossibleWinner) {
        groupWinners.insert(string() + possibleWinner + secondPossibleWinner);
      } else {
        groupWinners.insert(string() + possibleWinner + secondPossibleWinner);
      }
    } else if (possibleWinner != 0) {
      individualWinners.insert(possibleWinner);
    }
  }

  {
    char possibleWinner = board[0][2];
    char secondPossibleWinner = 0;

    for (int i = 0; i < 3; i++) {
      if (board[i][2 - i] != possibleWinner &&
          board[i][2 - i] != secondPossibleWinner) {
        if (secondPossibleWinner != 0) {
          possibleWinner = 0;
          secondPossibleWinner = 0;
          break;
        } else {
          secondPossibleWinner = board[i][2 - i];
        }
      }
    }

    if (secondPossibleWinner != 0) {
      if (possibleWinner < secondPossibleWinner) {
        groupWinners.insert(string() + possibleWinner + secondPossibleWinner);
      } else {
        groupWinners.insert(string() + possibleWinner + secondPossibleWinner);
      }
    } else if (possibleWinner != 0) {
      individualWinners.insert(possibleWinner);
    }
  }

  ofstream output("tttt.out");

  output << individualWinners.size() << "\n" << groupWinners.size() << endl;

  return 0;
}
