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
  string result = "";

  getline(cin, s);

  for (int i = 0; i < s.length(); i++) {
    result += s[i];
    if (isvowel(s[i])) i += 2;
  }

  cout << result;
}