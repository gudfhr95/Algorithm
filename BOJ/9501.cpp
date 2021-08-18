#include <iostream>

using namespace std;

int main() {
  int T, N, D, v, f, c, result;

  cin >> T;

  while (T--) {
    cin >> N >> D;

    result = 0;

    while (N--) {
      cin >> v >> f >> c;

      float distance = ((double)f / c) * v;

      if (distance >= D) result++;
    }

    cout << result << '\n';
  }
}