#include <cstring>
#include <iostream>

using namespace std;

long long mod = 1000000007;

int N, M, P;
long long d[101][101];

long long listen(int pos, int x) {
  int y = N - x;

  if (pos == P) {
    if (y == 0) {
      return 1;
    } else {
      return 0;
    }
  }

  long long &ret = d[pos][x];

  if (ret != -1) return ret;

  ret = 0;
  if (y > 0) {
    ret += listen(pos + 1, x + 1) * y;
  }
  if (x > M) {
    ret += listen(pos + 1, x) * (x - M);
  }
  ret %= mod;

  return ret;
}

int main() {
  cin >> N >> M >> P;

  memset(d, -1, sizeof(d));

  cout << listen(0, 0);
}
