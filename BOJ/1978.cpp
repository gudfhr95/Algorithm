#include <iostream>

using namespace std;

bool isPrimeNumber(int n) {
  if (n == 1) {
    return false;
  }
  if (n == 2) {
    return true;
  }

  for (int i = 2; i < n; ++i) {
    if ((n % i) == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  int number;
  int result = 0;

  cin >> N;

  for (int test_case = 0; test_case < N; ++test_case) {
    cin >> number;
    result += isPrimeNumber(number);
  }

  cout << result;

  return 0;
}