#include <iostream>

using namespace std;

int A[1000000];
int B[1000000];
int C[1000000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  int i = 0, j = 0, k = 0;
  while (i < N && j < M) {
    if (A[i] >= B[j]) {
      C[k++] = B[j++];
    } else {
      C[k++] = A[i++];
    }
  }

  while (i < N) {
    C[k++] = A[i++];
  }
  while (j < M) {
    C[k++] = B[j++];
  }

  for (int i = 0; i < N + M; i++) {
    cout << C[i] << ' ';
  }
}