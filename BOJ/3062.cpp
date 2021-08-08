#include <algorithm>
#include <iostream>

using namespace std;

bool isPalindrom(string s) {
  if (s.length() < 2) return true;

  if (s[0] != s[s.length() - 1]) return false;

  return isPalindrom(s.substr(1, s.length() - 2));
}

int main() {
  int T;
  string N, reversed;

  cin >> T;

  while (T--) {
    cin >> N;
    reversed = N;
    reverse(reversed.begin(), reversed.end());

    if (isPalindrom(to_string(stoi(N) + stoi(reversed)))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
