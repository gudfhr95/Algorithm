#include <algorithm>
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
  for (int i = 0; i < S.length(); i++) {
    cnt[pi[i]] += 1;
  }

  for (int i = S.length(); i > 0; i--) {
    cnt[pi[i - 1]] += cnt[i];
  }

  vector<pair<int, int>> result;
  for (int i = S.length(); i > 0; i = pi[i - 1]) {
    result.push_back({i, cnt[i] + 1});
  }

  reverse(result.begin(), result.end());

  cout << result.size() << '\n';
  for (auto &p : result) {
    cout << p.first << ' ' << p.second << '\n';
  }
}