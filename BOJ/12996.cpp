#include <cstring>
#include <iostream>

using namespace std;

int S, A, B, C;
long long d[50][50][50][50];
long long mod = 1000000007LL;

long long sing(int s, int a, int b, int c) {
  if (s == S) {
    if (a == A && b == B && c == C) {
      return 1;
    } else {
      return 0;
    }
  }

  long long& ret = d[s][a][b][c];

  if (ret != -1) return ret;

  ret = 0;
  ret += sing(s + 1, a + 1, b, c) % mod;
  ret += sing(s + 1, a, b + 1, c) % mod;
  ret += sing(s + 1, a, b, c + 1) % mod;
  ret += sing(s + 1, a + 1, b + 1, c) % mod;
  ret += sing(s + 1, a + 1, b, c + 1) % mod;
  ret += sing(s + 1, a, b + 1, c + 1) % mod;
  ret += sing(s + 1, a + 1, b + 1, c + 1) % mod;

  return ret % mod;
}

int main() {
  cin >> S >> A >> B >> C;

  memset(d, -1, sizeof(d));

  cout << sing(0, 0, 0, 0);
}
