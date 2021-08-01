#include <iostream>

using namespace std;

int main() {
  string s;
  int result = 0;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
      result++;
  }

  cout << result;
}