#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int rgb[1000][3];
int cache[1000][3];

int color(int n) {
  cache[0][0] = rgb[0][0];
  cache[0][1] = rgb[0][1];
  cache[0][2] = rgb[0][2];

  for (int i = 1; i < n; i++) {
    cache[i][0] = rgb[i][0] + min(cache[i - 1][1], cache[i - 1][2]);
    cache[i][1] = rgb[i][1] + min(cache[i - 1][0], cache[i - 1][2]);
    cache[i][2] = rgb[i][2] + min(cache[i - 1][0], cache[i - 1][1]);
  }

  return min({cache[n - 1][0], cache[n - 1][1], cache[n - 1][2]});
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> rgb[i][j];
    }
  }

  cout << color(N);
}