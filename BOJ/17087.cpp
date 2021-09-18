#include <iostream>

using namespace std;

int gcd(int a, int b) { return (a % b == 0) ? b : gcd(b, a % b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, S;

  cin >> N >> S;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    A[i] = abs(S - A[i]);
  }

  int result = A[0];
  for (int i = 1; i < N; i++) {
    result = gcd(result, A[i]);
  }

  cout << result;
}