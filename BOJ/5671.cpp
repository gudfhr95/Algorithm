#include <iostream>

using namespace std;

bool hasSameNumber(int n) {
  int numbers[10] = {
      0,
  };

  while (n > 0) {
    numbers[n % 10]++;

    n /= 10;
  }

  for (int i = 0; i < 10; i++) {
    if (numbers[i] > 1) return true;
  }

  return false;
}

int main() {
  int N, M;

  while (cin >> N >> M) {
    int result = 0;
    for (int i = N; i <= M; i++) {
      if (!hasSameNumber(i)) result++;
    }

    cout << result << '\n';
  }
}
