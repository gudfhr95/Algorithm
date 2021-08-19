#include <cmath>
#include <iostream>

using namespace std;

int convertToBase10(string s, int b) {
  int result = 0;

  for (int i = 0; i < s.length(); i++) {
    int digit;
    if (isalpha(s[i]))
      digit = s[i] - 'a' + 10;
    else
      digit = s[i] - '0';

    result += digit * pow(b, s.length() - 1 - i);
  }

  return result;
}

int main() {
  string s;

  cin >> s;

  if (s[0] != '0') {
    cout << s;
  } else {
    if (s[1] != 'x')
      cout << convertToBase10(s.substr(1, s.length() - 1), 8);
    else
      cout << convertToBase10(s.substr(2, s.length() - 2), 16);
  }
}