#include <iostream>

using namespace std;

int N;
int star[6144][6144];

void mark(int x, int y, int n) {
  if (n == 3) {
    star[y][x] = 1;
    star[y + 1][x - 1] = star[y + 1][x + 1] = 1;
    star[y + 2][x - 2] = star[y + 2][x - 1] = star[y + 2][x] =
        star[y + 2][x + 1] = star[y + 2][x + 2] = 1;

    return;
  }

  mark(x, y, n / 2);
  mark(x - n / 2, y + n / 2, n / 2);
  mark(x + n / 2, y + n / 2, n / 2);
}

int main() {
  cin >> N;

  mark(N - 1, 0, N);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < 2 * N; x++) {
      if (star[y][x]) {
        cout << '*';
      } else {
        cout << ' ';
      }
    }
    cout << '\n';
  }
}