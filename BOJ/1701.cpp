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
  string s;

  cin >> s;

  int result = 0;
  for(int i=s.length()-1; i>=0; i--){
    string substr = s.substr(i, s.length() - i);

    auto pi = preprocessing(substr);

    for(int cnt : pi){
      result = max(result, cnt);
    }
  }

  cout << result;
}