#include <iostream>

using namespace std;

char chess[100][100];

int main() {
  int R, C, A, B;

  cin >> R >> C >> A >> B;

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      char c;

      if ((x + y) % 2 == 0)
        c = 'X';
      else
        c = '.';

      for (int yy = 0; yy < A; yy++) {
        for (int xx = 0; xx < B; xx++) {
          chess[A * y + yy][B * x + xx] = c;
        }
      }
    }
  }

  for (int y = 0; y < R * A; y++) {
    for (int x = 0; x < C * B; x++) {
      cout << chess[y][x];
    }
    cout << '\n';
  }
}