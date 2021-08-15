#include <iostream>

using namespace std;

int main() {
  int result = 0;
  string s;

  for (int i = 0; i < 8; i++) {
    cin >> s;

    for (int j = 0; j < s.length(); j++) {
      if (s[j] == 'F' && (i + j) % 2 == 0) result++;
    }
  }

  cout << result;
}
