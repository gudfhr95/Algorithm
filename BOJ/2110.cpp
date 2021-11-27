#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, C;
int X[200000];
int dist = 1;

bool check(int x) {
  int result = 1;

  int last = X[0];
  for (int i = 1; i < N; i++) {
    if (X[i] - last >= x) {
      result++;
      last = X[i];
    }
  }

  return result >= C;
}

void install() {
  int l = dist;
  int r = X[N - 1] - X[0];

  if (C == 2) {
    dist = X[N - 1] - X[0];
    return;
  }

  while (l <= r) {
    int mid = (l + r) / 2;

    if (check(mid)) {
      dist = max(dist, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
}

int main() {
  cin >> N >> C;

  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }

  sort(X, X + N);

  install();

  cout << dist;
}