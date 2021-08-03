#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int T, index, result;
  string s;
  int beautiful[10];

  cin >> T;

  while (T--) {
    cin >> s;

    memset(beautiful, 0, sizeof(beautiful));
    result = 0;

    for (int i = 0; i < s.length(); i++) {
      index = s[i] - '0';
      beautiful[index] = 1;
    }

    for (int i = 0; i < 10; i++) {
      if (beautiful[i] == 1) result++;
    }

    cout << result << '\n';
  }
}