#include <iostream>

using namespace std;

bool isGoldmin(int n) {
  while (n > 0) {
    int remainder = n % 10;

    if (remainder != 4 && remainder != 7) return false;

    n /= 10;
  }

  return true;
}

int main() {
  int N;

  cin >> N;

  for (int i = N; i >= 4; i--) {
    if (isGoldmin(i)) {
      cout << i;
      break;
    }
  }
}