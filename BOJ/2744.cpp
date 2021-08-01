#include <iostream>

using namespace std;

int main() {
  string s;
  string answer = "";

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (isupper(s[i]))
      answer += tolower(s[i]);
    else
      answer += toupper(s[i]);
  }

  cout << answer;
}