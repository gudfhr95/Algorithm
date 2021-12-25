#include <iostream>

using namespace std;

const int INF = 987654321;

int d[101][101];

int main() {
  int N, M;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      d[i][j] = INF;
    }
  }

  int A, B;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;

    d[A][B] = d[B][A] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }

  int result = -1;
  int kv = 987654321;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      sum += d[i][j];
    }

    if (sum < kv) {
      result = i;
      kv = sum;
    }
  }

  cout << result;
}