#include <iostream>

using namespace std;

int N;
int paper[2187][2187];
int result[3];

bool isSame(int x, int y, int size) {
  int n = paper[y][x];

  for (int r = y; r < y + size; r++) {
    for (int c = x; c < x + size; c++) {
      if (paper[r][c] != n) return false;
    }
  }

  return true;
}

void tear(int x, int y, int size) {
  if (size == 1) {
    result[paper[y][x] + 1]++;
    return;
  }

  if (isSame(x, y, size)) {
    result[paper[y][x] + 1]++;
  } else {
    for (int r = y; r < y + size; r += size / 3) {
      for (int c = x; c < x + size; c += size / 3) {
        tear(c, r, size / 3);
      }
    }
  }
}

int main() {
  cin >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> paper[y][x];
    }
  }

  tear(0, 0, N);

  for (int i = 0; i < 3; i++) {
    cout << result[i] << '\n';
  }
}