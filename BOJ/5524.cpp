#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;

  while (N--) {
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
      if (isupper(s[i]))
        cout << (char)tolower(s[i]);
      else
        cout << s[i];
    }

    cout << '\n';
  }
}