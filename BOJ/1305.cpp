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
      pi[i] = j + 1;
      j += 1;
    } else {
      pi[i] = 0;
    }
  }

  return pi;
}

int main() {
  int L;
  string S;

  cin >> L >> S;

  auto pi = preprocessing(S);

  cout << L - pi[L - 1];
}