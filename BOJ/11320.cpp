#include <iostream>

using namespace std;

int main() {
  int T, A, B, result;

  cin >> T;

  while (T--) {
    cin >> A >> B;

    result = 0;

    for (int i = 1; i <= A / B; i++) {
      result += (i * 2) - 1;
    }

    cout << result << '\n';
  }
}