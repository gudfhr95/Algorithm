#include <iostream>

using namespace std;

int volumes[101];
bool d[101][1001];

int main() {
  int N, S, M;

  cin >> N >> S >> M;

  for (int i = 1; i <= N; i++) {
    cin >> volumes[i];
  }

  d[0][S] = true;
  for (int i = 0; i <= N - 1; i++) {
    for (int j = 0; j <= M; j++) {
      if (d[i][j] == false) continue;

      if (j - volumes[i + 1] >= 0) {
        d[i + 1][j - volumes[i + 1]] = true;
      }

      if (j + volumes[i + 1] <= M) {
        d[i + 1][j + volumes[i + 1]] = true;
      }
    }
  }

  int result = -1;
  for (int i = 0; i <= M; i++) {
    if (d[N][i]) result = i;
  }

  cout << result;
}