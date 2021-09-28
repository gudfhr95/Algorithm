#include <iostream>

using namespace std;

int day(int m, int n, int x, int y) {
  for (int i = 0; i < m; i++) {
    int temp = y + (n * i);

    if ((temp - x) % m == 0) return temp;
  }

  return -1;
}

int main() {
  int T, M, N, x, y;

  cin >> T;

  while (T--) {
    cin >> M >> N >> x >> y;

    cout << day(M, N, x, y) << '\n';
  }
}