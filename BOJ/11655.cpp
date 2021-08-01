#include <iostream>

using namespace std;

char ROT13(char c) {
  int index = 0;
  char standard = isupper(c) ? 'A' : 'a';

  index = c - standard;
  index = (index + 13) % 26;
  return index + standard;
}

int main() {
  string s;
  string result = "";

  getline(cin, s);

  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i]))
      result += ROT13(s[i]);
    else
      result += s[i];
  }

  cout << result;
}