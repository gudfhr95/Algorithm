#include <algorithm>
#include <iostream>

using namespace std;

int A[1000];
int cache[1000][2];

void lbs(int n) {
  for (int i = 0; i < n; i++) {
    cache[i][0] = 1;
    cache[i][1] = 1;

    for (int j = 0; j < i; j++) {
      if (A[j] > A[i]) {
        cache[i][1] = max({cache[i][1], cache[j][0] + 1, cache[j][1] + 1});
      } else if (A[j] < A[i]) {
        cache[i][0] = max({cache[i][0], cache[j][0] + 1});
      }
    }
  }
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  lbs(N);

  int result = -987654321;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      result = max(result, cache[i][j]);
    }
  }
  cout << result;
}