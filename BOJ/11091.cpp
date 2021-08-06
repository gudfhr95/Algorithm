#include <cstring>
#include <iostream>

using namespace std;

int ALPHABET[26];

int main() {
  int N;
  string s;
  bool result;

  cin >> N;
  cin.ignore();

  while (N--) {
    getline(cin, s);

    memset(ALPHABET, 0, sizeof(ALPHABET));
    result = true;

    for (int i = 0; i < s.length(); i++) {
      if (isalpha(s[i])) ALPHABET[tolower(s[i]) - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if (ALPHABET[i] == 0) {
        result = false;
        break;
      }
    }

    if (result)
      cout << "pangram\n";
    else {
      cout << "missing ";
      for (int i = 0; i < 26; i++) {
        if (ALPHABET[i] == 0) cout << (char)('a' + i);
      }
      cout << '\n';
    }
  }
}