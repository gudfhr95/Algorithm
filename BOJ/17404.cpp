#include <iostream>

using namespace std;

int rgb[1000][3];
int cache[1000][3];

int color(int n, int start) {
  for (int i = 0; i < 3; i++) {
    if (i == start) {
      cache[1][i] = 987654321;
    } else {
      cache[1][i] = rgb[1][i] + rgb[0][start];
    }
  }

  for (int i = 2; i < n; i++) {
    cache[i][0] = rgb[i][0] + min(cache[i - 1][1], cache[i - 1][2]);
    cache[i][1] = rgb[i][1] + min(cache[i - 1][0], cache[i - 1][2]);
    cache[i][2] = rgb[i][2] + min(cache[i - 1][0], cache[i - 1][1]);
  }

  int result = 987654321;
  for (int i = 0; i < 3; i++) {
    if (i == start) continue;
    result = min(result, cache[n - 1][i]);
  }
  return result;
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> rgb[i][j];
    }
  }

  int result = 987654321;
  for (int i = 0; i < 3; i++) {
    result = min(result, color(N, i));
  }
  cout << result;
}