#include <iostream>
#include <vector>

using namespace std;

vector<int> preprocessing(string p) {
  vector<int> pi(p.length());
  pi[0] = 0;

  int j = 0;
  for (int i = 1; i < p.length(); i++) {
    while (j > 0 && p[i] != p[j]) {
      j = pi[j - 1];
    }

    if (p[i] == p[j]) {
      pi[i] = ++j;
    } else {
      pi[i] = 0;
    }
  }

  return pi;
}

int main() {
  string S;

  cin >> S;

  auto pi = preprocessing(S);

  vector<int> cnt(S.length() + 1);
  for (int i = 0; i < S.length() - 1; i++) {
    cnt[pi[i]] += 1;
  }

  for (int i = S.length(); i != 0; i = pi[i - 1]) {
    if (cnt[i] >= 1) {
      cout << S.substr(0, i) << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';

  return 0;
}