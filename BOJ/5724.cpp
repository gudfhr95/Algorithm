#include <iostream>

using namespace std;

int main() {
  int n, result;

  while (true) {
    cin >> n;

    if (n == 0) break;

    result = 0;

    for (int i = 1; i <= n; i++) {
      result += i * i;
    }

    cout << result << '\n';
  }
}
