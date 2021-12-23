#include <cstring>
#include <iostream>

using namespace std;

long long mod = 100000;
char open[3] = {'(', '{', '['};
char close[3] = {')', '}', ']'};

string S;
long long d[200][200];

long long go(int start, int end) {
  if (start > end) {
    return 1;
  }

  long long& ret = d[start][end];

  if (ret != -1) return ret;

  ret = 0;
  for (int k = start + 1; k <= end; k += 2) {
    for (int l = 0; l < 3; l++) {
      if (S[start] == open[l] || S[start] == '?') {
        if (S[k] == close[l] || S[k] == '?') {
          long long temp = go(start + 1, k - 1) * go(k + 1, end);
          ret += temp;
          if (ret >= mod) {
            ret = mod + ret % mod;
          }
        }
      }
    }
  }

  return ret;
}

int main() {
  int N;

  cin >> N >> S;

  memset(d, -1, sizeof(d));

  long long result = go(0, N - 1);
  if (result >= mod) {
    printf("%05lld\n", result % mod);
  } else {
    printf("%lld\n", result);
  }
}
