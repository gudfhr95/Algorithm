#include <iostream>

using namespace std;

bool isPalindrom(string s) {
  if (s.length() < 2) return true;

  if (s[0] != s[s.length() - 1]) return false;

  return isPalindrom(s.substr(1, s.length() - 2));
}

int main() {
  int n;
  string s;

  cin >> n;
  cin.ignore();

  while (n--) {
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
      if (isalpha(s[i])) s[i] = tolower(s[i]);
    }

    if (isPalindrom(s))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}