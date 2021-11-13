#include <iostream>
#include <vector>

using namespace std;

char flip(char x) {
  if (x == 'H') {
    return 'T';
  } else {
    return 'H';
  }
}

int main() {
  int N;

  cin >> N;

  vector<string> coins(N);

  for (int i = 0; i < N; i++) {
    cin >> coins[i];
  }

  int result = N * N;

  for (int state = 0; state < (1 << N); state++) {
    int sum = 0;
    for (int x = 0; x < N; x++) {
      int cnt = 0;
      for (int y = 0; y < N; y++) {
        char cur = coins[y][x];
        if (state & (1 << y)) {
          cur = flip(cur);
        }
        if (cur == 'T') {
          cnt += 1;
        }
      }
      sum += min(cnt, N - cnt);
    }
    if (result > sum) result = sum;
  }

  cout << result;
}