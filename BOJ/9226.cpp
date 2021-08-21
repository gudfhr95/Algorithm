#include <iostream>

using namespace std;

bool isvowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  else
    return false;
}

int main() {
  string s;

  while (true) {
    cin >> s;

    if (s == "#") break;

    for (int i = 0; i < s.length(); i++) {
      if (isvowel(s[i])) {
        s = s.substr(i, s.length() - i) + s.substr(0, i);
        break;
      }
    }

    cout << s << "ay\n";
  }
}
