#include <iostream>

using namespace std;

char convert(char c) {
  int index = c - 'A' - 3;
  if (index < 0) index += 26;

  return index + 'A';
}

int main() {
  string s;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    cout << convert(s[i]);
  }
}