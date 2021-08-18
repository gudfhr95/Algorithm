#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int T, n, m, result;

  cin >> T;

  while (T--) {
    cin >> n >> m;

    result = 0;

    for (int a = 1; a < n; a++) {
      for (int b = a + 1; b < n; b++) {
        if ((int)(pow(a, 2) + pow(b, 2) + m) % (a * b) == 0) result++;
      }
    }

    cout << result << '\n';
  }
}