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

vector<int> kmp(string s, string p) {
  vector<int> result;

  auto pi = preprocessing(p);

  int j = 0;
  for (int i = 0; i < s.length(); i++) {
    while (j > 0 && s[i] != p[j]) {
      j = pi[j - 1];
    }

    if (s[i] == p[j]) {
      if (j == p.length() - 1) {
        result.push_back(i - p.length() + 1);
        j = pi[j];
      } else {
        j += 1;
      }
    }
  }

  return result;
}

int main() {
  string A, B;

  cin >> A >> B;

  B += B.substr(0, B.length() - 1);

  auto result = kmp(B, A);

  cout << result.size();
}