#include <iostream>

using namespace std;

int main() {
  int N, M;

  cin >> N >> M;

  int A[N];

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 1; i <= M; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (A[j] % i > A[j + 1] % i) swap(A[j], A[j + 1]);
    }
  }

  for (int i = 0; i < N; i++) {
    cout << A[i] << '\n';
  }
}