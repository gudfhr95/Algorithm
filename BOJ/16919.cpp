#include <iostream>

#define hash _hash

using namespace std;

int hash(string s) {
  int result = 0;

  for (int i = 0; i < s.length(); i++) {
    result *= 256;
    result += ((int)s[i]);
    result %= 127;
  }

  return result;
}

bool match(string s, string p) {
  int n = s.length();
  int m = p.length();

  if (n < m) return false;

  int hP = hash(p);
  int hS = hash(s.substr(0, m));

  int first = 1;
  for (int i = 0; i < m - 1; i++) {
    first = (first * 256) % 127;
  }

  for (int i = 0; i <= n - m; i++) {
    if (hS == hP) {
      if (s.substr(i, m) == p) {
        return true;
      }
    }

    if (i + m < n) {
      hS = hS - (s[i] * first) % 127;
      hS = (hS + 127) % 127;
      hS = ((hS * 256) % 127 + s[i + m]) % 127;
    }
  }

  return false;
}

int main() {
  string S, P;

  cin >> S >> P;

  cout << match(S, P);
}