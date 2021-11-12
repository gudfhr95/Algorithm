#include <iostream>

using namespace std;

int N, M;
int A[50][50];
int B[50][50];

void swap(int x, int y) {
  for (int r = y; r < y + 3; r++) {
    for (int c = x; c < x + 3; c++) {
      A[r][c] = 1 - A[r][c];
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%1d", &A[y][x]);
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%1d", &B[y][x]);
    }
  }

  int result = 0;
  if (N < 3 || M < 3) {
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        if (A[y][x] != B[y][x]) {
          cout << -1;
          return 0;
        }
      }
    }
    cout << result;
    return 0;
  }

  for (int y = 0; y < N - 2; y++) {
    for (int x = 0; x < M - 2; x++) {
      if (A[y][x] != B[y][x]) {
        swap(x, y);
        result++;
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (A[y][x] != B[y][x]) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << result;
  return 0;
}