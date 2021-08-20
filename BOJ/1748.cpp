#include <iostream>

using namespace std;

int DIGITS[9] = {9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 90000000};

int main() {
  int N;
  long long result = 0;

  cin >> N;

  for (int i = 0; i < 9; i++) {
    if (N - DIGITS[i] < 0) {
      result += N * (i + 1);
      break;
    }

    result += DIGITS[i] * (i + 1);
    N -= DIGITS[i];
  }

  cout << result;
}