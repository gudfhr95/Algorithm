#include <algorithm>
#include <iostream>

using namespace std;

bool isLucky(string s) {
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1]) return false;
  }
  return true;
}

int main() {
  string s;

  cin >> s;

  sort(s.begin(), s.end());

  int result = 0;
  do {
    if (isLucky(s)) {
      result++;
    }
  } while (next_permutation(s.begin(), s.end()));

  cout << result;
}