#include <iostream>

using namespace std;

int main() {
  int T, A, B;

  cin >> T;

  while (T--) {
    cin >> A >> B;

    long long result = 0;
    for (int i = 1; i <= A / B; i++) {
      result += (2 * i) - 1;
    }

    cout << result << '\n';
  }
}