#include <iostream>
#include <string>
#include <cstdio> 

int getScore();
char getGrade(int score);
void result(char grade);

double calculateFinalGrade();
void printFinalGrade(double fg);

int main() {
  std::cout << "Welcome to the letter grade app!" << "\n";
  int choice = 0;
  while (choice != 3) {
    std::cout << "What Would You Like To Do?:\n";
    std::cout << "1. Convert Numerical Score To Grade\n2. Final Grade Calculator\n3. Exit Program\n";
    std::cout << "Enter Your Choice: ";
    std::cin >> choice;
    if (choice == 1) {
      int num = getScore();
      char letter = getGrade(num);
      result(letter);
    }
    else if (choice == 2) {
      double finalGrade = calculateFinalGrade();
      printFinalGrade(finalGrade);
    }
    else if (choice == 3) {
      std::cout << "Goodbye.\n";
    }
    else {
      std::cout << "Invalid Input. Please re-enter your choice again.\n";
    }
  }
  return 0;
}

int getScore() {
  bool validateScore = true;
  int score;
  while (validateScore == true) {
    std::cout << "Enter Score (0-100): ";
    std::cin >> score;
    if (score > 100 || score < 0) {
      std::cout << "Invalid input. Try again.\n";
    }
    else {
      validateScore = false;
    }
  }
  return score; 
}

char getGrade(int score) {
  char letter = 'A';
  if (score < 60) {
    letter = 'F';
  } 
  else if (score < 70) {
    letter = 'D';
  }
  else if (score < 80) {
    letter = 'C';
  }
  else if (score < 90) {
    letter = 'B';
  }
  else {
    letter = 'A';
  }
  return letter;
}

void result(char grade) {
  std::cout << "Letter Grade: " << grade << "\n";
}

double calculateFinalGrade() {
  double G; 
  double F; 
  double w; 
  double C; 
  std::cout << "Enter your FINAL EXAM GRADE: ";
  std::cin >> F;
  std::cout << "Enter your WEIGHT OF FINAL EXAM: ";
  std::cin >> w;
  std::cout << "Enter your CURRENT GRADE: ";
  std::cin >> C;
  w /= 100;
  G = F*w+((1 - w)*C);
  return G;
}

void printFinalGrade(double fg) {
  std::cout << "Your Final Grade Is: ";
  printf("%.2f\n", fg);
}
