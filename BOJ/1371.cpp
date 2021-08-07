#include <iostream>

int ALPHABET[26] = {
    0,
};

using namespace std;

int main() {
  string s;
  int max = -987654321;

  while (cin >> s) {
    for (int i = 0; i < s.length(); i++) {
      ALPHABET[s[i] - 'a']++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (ALPHABET[i] > max) {
      max = ALPHABET[i];
    }
  }

  for (int i = 0; i < 26; i++) {
    if (ALPHABET[i] == max) {
      cout << (char)(i + 'a');
    }
  }
}