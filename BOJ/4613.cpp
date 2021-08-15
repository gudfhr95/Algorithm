#include <iostream>

using namespace std;

int checksum(string s) {
  int result = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') continue;

    result += (s[i] - 'A' + 1) * (i + 1);
  }

  return result;
}

int main(void) {
  string s;

  while (true) {
    getline(cin, s);
    if (s == "#") break;

    cout << checksum(s) << '\n';
  }
}
