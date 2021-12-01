#include <iostream>

using namespace std;

string format;
int result = 0;

bool check(string s) {
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1]) return false;
  }

  return true;
}

void make(string s) {
  if (s.length() == format.length()) {
    if (check(s)) {
      result += 1;
    }
    return;
  }

  if (format[s.length()] == 'd') {
    for (int i = 0; i < 10; i++) {
      make(s + (char)('0' + i));
    }
  } else {
    for (int i = 0; i < 26; i++) {
      make(s + (char)('a' + i));
    }
  }
}

int main() {
  cin >> format;

  make("");

  cout << result;
}