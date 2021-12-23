#include <iostream>

using namespace std;

int A[100][100];
int B[100][100];

int main() {
  int N, M;

  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> A[y][x];
    }
  }

  int K;

  cin >> M >> K;

  for (int y = 0; y < M; y++) {
    for (int x = 0; x < K; x++) {
      cin >> B[y][x];
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < K; x++) {
      int sum = 0;
      for (int k = 0; k < M; k++) {
        sum += A[y][k] * B[k][x];
      }
      cout << sum << ' ';
    }
    cout << '\n';
  }
}