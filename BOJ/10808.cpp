#include <iostream>

using namespace std;

int alphabet[26] = {
    0,
};

int main() {
  string s;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    alphabet[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    cout << alphabet[i] << ' ';
  }
}