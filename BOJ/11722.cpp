#include <iostream>

using namespace std;

int A[1000];
int cache[1000];

void lds(int n) {
  for (int i = 0; i < n; i++) {
    cache[i] = 1;
    for (int j = 0; j < i; j++) {
      if (A[j] > A[i]) cache[i] = max(cache[i], cache[j] + 1);
    }
  }
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  lds(N);

  int result = -987654321;
  for (int i = 0; i < N; i++) {
    result = max(result, cache[i]);
  }
  cout << result;
}