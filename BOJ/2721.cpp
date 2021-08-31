#include <iostream>

using namespace std;

int Triangle(int n) {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    result += i;
  }

  return result;
}

int main() {
  int T, n;

  cin >> T;

  while (T--) {
    cin >> n;

    long long result = 0;
    for (int i = 1; i <= n; i++) {
      result += i * Triangle(i + 1);
    }

    cout << result << '\n';
  }
}