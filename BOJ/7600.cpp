#include <cstring>
#include <iostream>

using namespace std;

int ALPHABET[26];

void countAlpha(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i])) ALPHABET[tolower(s[i]) - 'a'] = 1;
  }
}

int main() {
  string s;
  int result;

  while (true) {
    getline(cin, s);

    memset(ALPHABET, 0, sizeof(ALPHABET));
    result = 0;

    if (s == "#") break;

    countAlpha(s);

    for (int i = 0; i < 26; i++) {
      result += ALPHABET[i];
    }

    cout << result << '\n';
  }
}