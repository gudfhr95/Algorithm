#include <cstring>
#include <iostream>

using namespace std;

int N;
int r[501];
int c[501];
int d[501][501];

int mult(int start, int end) {
  if (start == end) return 0;

  int &ret = d[start][end];

  if (ret != -1) return ret;

  if (start == end - 1) {
    ret = r[start] * c[start] * c[end];
    return ret;
  }

  ret = 987654321;
  for (int i = 0; i < end - start; i++) {
    int cost = mult(start, start + i) + mult(start + i + 1, end) +
               (r[start] * c[start + i] * c[end]);

    ret = min(ret, cost);
  }

  return ret;
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> r[i] >> c[i];
  }

  memset(d, -1, sizeof(d));

  cout << mult(1, N);
}
