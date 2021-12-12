#include <iostream>

using namespace std;

int N, M;
int A[10000];

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int result = 0;

  int l = 0;
  int r = 0;
  int sum = A[0];
  while (l <= r && r < N) {
    if (sum == M) {
      result++;
      sum += A[++r];
    } else if (sum < M) {
      sum += A[++r];
    } else {
      sum -= A[l++];
      if (l > r && l < N) {
        r = l;
        sum = A[l];
      }
    }
  }

  cout << result;
}