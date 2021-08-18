#include <iostream>

using namespace std;

int main() {
  int N, M, i, j, k;
  int BASKET[101] = {
      0,
  };

  cin >> N >> M;

  while (M--) {
    cin >> i >> j >> k;

    for (int index = i; index <= j; index++) {
      BASKET[index] = k;
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << BASKET[i] << ' ';
  }
}