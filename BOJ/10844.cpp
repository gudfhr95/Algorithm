#include <cstring>
#include <iostream>

using namespace std;

int cache[101][10];

void stair(int n) {
  for (int i = 2; i <= n; i++) {
    cache[i][0] = cache[i - 1][1];
    cache[i][9] = cache[i - 1][8];

    for (int j = 1; j <= 8; j++) {
      cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % 1000000000;
    }
  }
}

int main() {
  memset(cache, -1, sizeof(cache));

  for (int i = 0; i < 10; i++) {
    cache[1][i] = 1;
  }

  int N;

  cin >> N;

  stair(N);

  int result = 0;
  for (int i = 1; i <= 9; i++) {
    result = (result + cache[N][i]) % 1000000000;
  }
  cout << result;
}