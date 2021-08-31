#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;

  while (N--) {
    cin >> s;

    int last = s[s.length() - 1] - '0';

    if (last % 2 == 0)
      cout << "even\n";
    else
      cout << "odd\n";
  }
}