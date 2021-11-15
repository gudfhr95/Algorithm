#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s;

  cin >> s;

  bool hasZero = false;
  int sum = 0;
  for (const char c : s) {
    int n = c - '0';
    if (n == 0) {
      hasZero = true;
    }

    sum += n;
  }

  if (!hasZero || sum % 3 != 0) {
    cout << -1;
    return 0;
  }

  sort(s.begin(), s.end(), greater<>());

  cout << s;
  return 0;
}