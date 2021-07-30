#include <cmath>
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

void getPrimeSumAndMin(int M, int N) {
  int result[2] = {0, 0};

  for (int i = M; i <= N; ++i) {
    if (isPrimeNumber(i)) {
      result[0] += i;
      if (result[1] == 0) {
        result[1] = i;
      }
    }
  }

  if (result[1] == 0) {
    cout << -1;
  } else {
    cout << result[0] << '\n' << result[1];
  }
}

int main() {
  int M, N;

  cin >> M >> N;

  getPrimeSumAndMin(M, N);

  return 0;
}