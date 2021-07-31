#include <iostream>

using namespace std;

int main() {
  int T, n, sum, min;
  cin >> T;

  while (T--) {
    sum = 0;
    min = 987654321;

    for (int i = 0; i < 7; i++) {
      cin >> n;
      if (n % 2 == 0) {
        sum += n;
        if (n < min) min = n;
      }
    }

    cout << sum << ' ' << min << '\n';
  }
}