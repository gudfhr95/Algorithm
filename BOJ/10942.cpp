#include <iostream>

using namespace std;

int A[2000];
bool d[2000][2000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - i; j++) {
      if (i == 0) {
        d[j][j] = true;
      } else if (i == 1) {
        if (j + i > N - 1) continue;

        d[j][j + i] = d[j + i][j] = (A[j] == A[j + i]);
      } else {
        d[j][j + i] = d[j + i][j] = ((A[j] == A[j + i]) && d[j + 1][j + i - 1]);
      }
    }
  }

  int M;

  cin >> M;

  for (int i = 0; i < M; i++) {
    int S, E;

    cin >> S >> E;

    cout << d[S - 1][E - 1] << '\n';
  }
}
