#include <iostream>

using namespace std;

int getPrimeNumbers(int n) {
  int result = 0;
  bool* PrimeArray = new bool[(2 * n) + 1];

  for (int i = 2; i <= (2 * n); ++i) {
    PrimeArray[i] = true;
  }

  for (int i = 2; i * i <= (2 * n); ++i) {
    if (PrimeArray[i]) {
      for (int j = i * 2; j <= (2 * n); j += i) {
        PrimeArray[j] = false;
      }
    }
  }

  for (int i = n + 1; i <= (2 * n); ++i) {
    if (PrimeArray[i]) {
      result += 1;
    }
  }

  return result;
}

int main() {
  int n;

  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    cout << getPrimeNumbers(n) << '\n';
  }

  return 0;
}