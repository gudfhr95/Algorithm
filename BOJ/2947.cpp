#include <algorithm>
#include <iostream>

using namespace std;

int NUMBERS[5];

void printNumbers() {
  for (int i = 0; i < 5; i++) {
    cout << NUMBERS[i] << ' ';
  }
  cout << '\n';
}

bool checkNumbers() {
  for (int i = 0; i < 5; i++) {
    if (NUMBERS[i] != i + 1) return false;
  }

  return true;
}

void swapNumbers() {
  for (int i = 0; i < 4; i++) {
    if (NUMBERS[i] > NUMBERS[i + 1]) {
      swap(NUMBERS[i], NUMBERS[i + 1]);
      printNumbers();
    }
  }
}

int main() {
  int n;

  for (int i = 0; i < 5; i++) {
    cin >> n;
    NUMBERS[i] = n;
  }

  while (true) {
    swapNumbers();

    if (checkNumbers()) break;
  }
}