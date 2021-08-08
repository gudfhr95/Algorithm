#include <iostream>

using namespace std;

int main() {
  string s, result;
  int parity;

  while (true) {
    cin >> s;

    if (s == "#") break;

    parity = 0;
    result = s.substr(0, s.length() - 1);

    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == '1') parity++;
    }

    if (s[s.length() - 1] == 'e') {
      if (parity % 2 == 0)
        result += '0';
      else
        result += '1';
    } else {
      if (parity % 2 == 0)
        result += '1';
      else
        result += '0';
    }

    cout << result << '\n';
  }
}