#include <iostream>

using namespace std;

string play(string s) {
  int result = 1;

  for (int i = 0; i < s.length(); i++) {
    result *= (s[i] - '0');
  }

  return to_string(result);
}

int main() {
  string s;

  while (true) {
    cin >> s;

    if (s == "0") break;

    while (s.length() > 1) {
      cout << s << ' ';
      s = play(s);
    }

    cout << s << '\n';
  }
}