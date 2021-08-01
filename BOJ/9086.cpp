#include <iostream>

using namespace std;

int main() {
  int T;
  string s;

  cin >> T;

  while (T--) {
    cin >> s;

    cout << s[0] << s[s.length() - 1] << '\n';
  }
}