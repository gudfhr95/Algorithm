#include <cstring>
#include <iostream>

using namespace std;

int N;
int house[32][32];
long long cache[32][32][3];

long long move(int x, int y, int d) {
  if (x == N - 1 && y == N - 1) {
    return 1;
  }

  long long& ret = cache[y][x][d];

  if (ret != -1) return ret;

  long long result = 0;
  if (d == 0) {
    if (x + 1 <= N - 1 && house[y][x + 1] != 1) {
      result += move(x + 1, y, 0);
    }

    if (x + 1 <= N - 1 && y + 1 <= N - 1 && house[y][x + 1] != 1 &&
        house[y + 1][x] != 1 && house[y + 1][x + 1] != 1) {
      result += move(x + 1, y + 1, 2);
    }
  } else if (d == 1) {
    if (y + 1 <= N - 1 && house[y + 1][x] != 1) {
      result += move(x, y + 1, 1);
    }

    if (x + 1 <= N - 1 && y + 1 <= N - 1 && house[y][x + 1] != 1 &&
        house[y + 1][x] != 1 && house[y + 1][x + 1] != 1) {
      result += move(x + 1, y + 1, 2);
    }
  } else if (d == 2) {
    if (x + 1 <= N - 1 && house[y][x + 1] != 1) {
      result += move(x + 1, y, 0);
    }

    if (y + 1 <= N - 1 && house[y + 1][x] != 1) {
      result += move(x, y + 1, 1);
    }

    if (x + 1 <= N - 1 && y + 1 <= N - 1 && house[y][x + 1] != 1 &&
        house[y + 1][x] != 1 && house[y + 1][x + 1] != 1) {
      result += move(x + 1, y + 1, 2);
    }
  }

  return ret = result;
}

int main() {
  cin >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> house[y][x];
    }
  }

  memset(cache, -1, sizeof(cache));

  cout << move(1, 0, 0);
}
