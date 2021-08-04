#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int T, result;
  int alphabet[26];
  string s;

  cin >> T;

  while (T--) {
    cin >> s;

    result = 0;
    memset(alphabet, 0, sizeof(alphabet));

    for (int i = 0; i < s.length(); i++) {
      alphabet[s[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
      if (alphabet[i] == 0) {
        result += i + 'A';
      }
    }

    cout << result << '\n';
  }
}