#include <cstring>
#include <iostream>

using namespace std;

int N;
int coke[1000];
int d[1000][1000];

int cheer(int start, int end) {
  if (start >= end) return 0;

  int &ret = d[start][end];

  if (ret != -1) return ret;

  ret = cheer(start + 1, end);
  for (int k = start + 1; k <= end; k++) {
    int cur = 0;

    if (coke[start] == coke[k]) {
      cur = cheer(start + 1, k - 1) + cheer(k + 1, end) + 1;
    }

    ret = max(ret, cur);
  }

  return ret;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> coke[i];
  }

  memset(d, -1, sizeof(d));

  cout << cheer(0, N - 1);
}
