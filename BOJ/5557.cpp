#include <iostream>

using namespace std;

int N;
int A[100];
long long d[101][21];

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  d[0][A[0]] = 1;
  for (int i = 1; i < N - 1; i++) {
    for (int j = 0; j <= 20; j++) {
      if (d[i - 1][j] == 0) continue;

      if (j + A[i] <= 20) {
        d[i][j + A[i]] += d[i - 1][j];
      }

      if (j - A[i] >= 0) {
        d[i][j - A[i]] += d[i - 1][j];
      }
    }
  }

  cout << d[N - 2][A[N - 1]];
}
