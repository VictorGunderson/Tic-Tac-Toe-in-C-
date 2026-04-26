#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>


void printBoard(std::vector<std::vector<std::string>> board);
bool checkWin(std::vector<std::vector<std::string>> board, std::string player);


int main() {
  std::vector<std::vector<std::string>> board = 
  {
    {"","",""},
    {"","",""},
    {"","",""}
  };
  std::vector<std::string> letters = {"x","o"};
  std::cout << "Welcome to Tic Tac Toe\n";

  int chooseRandom = rand() % letters.size();
  std::string p1 = letters[chooseRandom];
  letters.erase(letters.begin() + chooseRandom);
  std::string p2 = letters.at(0);

  std::vector<std::string> playerList = {p1, p2};

  std::cout << "The First Player is " << p1 << "\n";
  std::cout << "The Second Player is " << p2 << "\n\n";

  int randplayer = rand() % 2;
  int fullCounter = 0;

  bool gameRunning = true;
  while (gameRunning) {
    printBoard(board);
    std::cout << "\n";
    std::cout << "Player " << playerList[randplayer] << " make your move (1-9): ";
    int tttCell;
    std::cin >> tttCell;

    if (tttCell < 1 || tttCell > 9) {
      std::cout << "Invalid Input\n\n";
      continue;
    }

    tttCell -= 1;

    int row = tttCell / 3;
    int col = tttCell % 3;

    if (board[row][col] != "") {
      std::cout << "Cell already taken. Try again.\n\n";
      continue;
    } 
    board[row][col] = playerList[randplayer];

    fullCounter = fullCounter + 1;

    if (checkWin(board, playerList[randplayer]) == true) {
      std::cout << playerList[randplayer] << " has won the game!";
      gameRunning = false;
    }
    else if (fullCounter == 9) {
      std::cout << "Tie!";
      gameRunning = false;
    }
    else {
      if (playerList[randplayer] == p1) {
        randplayer++;
      }
      else {
        randplayer--;
      }
    }

  }
  return 0;
}

void printBoard(std::vector<std::vector<std::string>> board) {
  std::cout << "-----------\n";
  for (int i = 0; i < board.size(); i++) {
    for(int j = 0; j < board[i].size(); j++) {
      std::cout << "| " << board[i][j] << " ";
    }
    std::cout << "|";
    std::cout << "\n-----------\n";
  }
}

bool checkWin(std::vector<std::vector<std::string>> board, std::string player) {
  int countRows = 0;
  int countCols = 0;
  int countDiag = 0;

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (board[i][j] == player) {
        countRows++;
      }
    }
    if (countRows == 3) {
      return true;
    }
    else {
      countRows = 0;
    }
  }

  for (int j = 0; j < board[0].size(); j++) {
    for (int i = 0; i < board.size(); i++) {
      if (board[i][j] == player) {
        countCols++;
      }
    }
    if (countCols == 3) {
      return true;
    }
    else {
      countCols = 0;
    }
  }

  for (int i = 0; i < board.size(); i++) {
    if (board[i][i] == player) {
      countDiag++;
    }
  }
  if (countDiag == 3) {
    return true;
  }
  else {
    countDiag = 0;
  }

  int inBounds = board.size() - 1;
  for (int i = 0; i < board.size(); i++) {
    if (board[i][inBounds - i] == player) {
      countDiag++;
    }
  }
  if (countDiag == 3) {
    return true;
  }
  else {
    countDiag = 0;
  }

  return false;
}
