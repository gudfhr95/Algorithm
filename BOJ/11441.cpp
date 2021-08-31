#include <iostream>

using namespace std;

int SUM[100001];

int main() {
  int N;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  int A[N];

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += A[i - 1];
    SUM[i] = sum;
  }

  int M, i, j;

  cin >> M;

  while (M--) {
    cin >> i >> j;

    cout << SUM[j] - SUM[i - 1] << '\n';
  }
}