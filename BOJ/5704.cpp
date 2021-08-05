#include <cstring>
#include <iostream>

using namespace std;

int ALPHABET[26];

int main() {
  string s;
  bool result;

  while (true) {
    getline(cin, s);

    if (s == "*") break;

    memset(ALPHABET, 0, sizeof(ALPHABET));
    result = true;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] != ' ') ALPHABET[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if (ALPHABET[i] == 0) {
        result = false;
        break;
      }
    }

    if (result)
      cout << 'Y' << '\n';
    else
      cout << "N\n";
  }
}