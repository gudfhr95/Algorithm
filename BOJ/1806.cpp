#include <iostream>

using namespace std;

int N, S;
int A[100000];

int main() {
  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int result = 987654321;
  int l = 0;
  int r = 0;
  int sum = A[0];
  while (l <= r && r < N) {
    if (sum >= S) {
      result = min(result, r - l + 1);
      sum -= A[l++];
    } else if (sum < S) {
      sum += A[++r];
    }
  }

  if (result == 987654321) {
    cout << 0;
  } else {
    cout << result;
  }
}