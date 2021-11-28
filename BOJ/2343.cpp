#include <iostream>

using namespace std;

int N, M;
int lectures[100000];

bool check(int length) {
  int result = 0;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (lectures[i] > length) {
      return false;
    }

    if (sum + lectures[i] > length) {
      result++;
      sum = lectures[i];
    } else {
      sum += lectures[i];
    }
  }

  if (sum != 0) {
    result++;
  }

  return result <= M;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> lectures[i];
  }

  int l = 0;
  int r = 1000000000;
  int result = 1000000000;
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