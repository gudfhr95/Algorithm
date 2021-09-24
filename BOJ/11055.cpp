#include <iostream>

using namespace std;

int A[1000];
int cache[1000];

void maxLis(int n) {
  for (int i = 0; i < n; i++) {
    cache[i] = A[i];
    for (int j = 0; j < i; j++) {
      if (A[j] < A[i]) {
        cache[i] = max(cache[i], cache[j] + A[i]);
      }
    }
  }
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  maxLis(N);

  int result = -987654321;
  for (int i = 0; i < N; i++) {
    result = max(result, cache[i]);
  }
  cout << result;
}