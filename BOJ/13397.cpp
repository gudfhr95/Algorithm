#include <iostream>

using namespace std;

int N, M;
int A[5000];

bool check(int m) {
  int result = 1;

  int t1 = A[0];
  int t2 = A[0];
  for (int i = 1; i < N; i++) {
    t1 = min(t1, A[i]);
    t2 = max(t2, A[i]);

    if (t2 - t1 > m) {
      result += 1;
      t1 = A[i];
      t2 = A[i];
    }
  }

  return result <= M;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int l = 0;
  int r = 10000;
  int result = 987654321;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (check(mid)) {
      result = min(result, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << result;
}