#include <iostream>

using namespace std;

char getAffineCipher(int a, int b, char c) {
  return ((a * (c - 'A') + b) % 26) + 'A';
}

int main() {
  int T, a, b;
  string s, result;

  cin >> T;

  while (T--) {
    cin >> a >> b >> s;

    result = "";

    for (int i = 0; i < s.length(); i++) {
      result += getAffineCipher(a, b, s[i]);
    }

    cout << result << '\n';
  }
}