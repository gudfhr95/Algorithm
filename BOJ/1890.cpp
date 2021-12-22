#include <cstring>
#include <iostream>

using namespace std;

int N;
int board[100][100];
long long d[100][100];

long long move(int x, int y) {
  if (x == N - 1 && y == N - 1) return 1;

  long long& ret = d[y][x];

  if (ret != -1) return ret;

  ret = 0;

  int nx = x + board[y][x];
  if (nx <= N - 1) {
    ret += move(nx, y);
  }

  int ny = y + board[y][x];
  if (ny <= N - 1) {
    ret += move(x, ny);
  }

  return ret;
}

int main() {
  cin >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  memset(d, -1, sizeof(d));

  cout << move(0, 0);
}
