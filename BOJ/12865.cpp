#include <iostream>

using namespace std;

int W[101];
int V[101];
int d[101][100001];

int main() {
  int N, K;

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> W[i] >> V[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      d[i][j] = d[i - 1][j];
      if (j - W[i] >= 0) {
        d[i][j] = max(d[i][j], d[i - 1][j - W[i]] + V[i]);
      }
    }
  }

  cout << d[N][K];
}