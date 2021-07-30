#include <iostream>

using namespace std;

bool isPalindrome(string s) {
  if (s.length() == 1) {
    return true;
  }
  if (s.length() == 2 && s[0] == s[1]) {
    return true;
  }

  if (s[0] == s[s.length() - 1]) {
    return isPalindrome(s.substr(1, s.length() - 2));
  } else {
    return false;
  }
}

int main() {
  string input;
  cin >> input;
  cout << isPalindrome(input);
}