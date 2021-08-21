#include <iostream>

using namespace std;

int main() {
  int T;
  string s, r;

  cin >> T;
  cin.ignore();

  while (T--) {
    getline(cin, s);
    getline(cin, r);

    char rule[26];
    for (int i = 0; i < 26; i++) {
      rule[i] = r[i];
    }

    for (int i = 0; i < s.length(); i++) {
      if (isalpha(s[i])) s[i] = (char)rule[s[i] - 'A'];
    }

    cout << s << '\n';
  }
}
