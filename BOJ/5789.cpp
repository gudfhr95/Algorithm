#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;

  while (N--) {
    cin >> s;

    if (s[s.length() / 2 - 1] != s[s.length() / 2])
      cout << "Do-it-Not\n";
    else
      cout << "Do-it\n";
  }
}