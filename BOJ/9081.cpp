#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T;
  string s;

  cin >> T;

  while (T--) {
    cin >> s;

    string original = s;
    if (!next_permutation(s.begin(), s.end()))
      cout << original << '\n';
    else
      cout << s << '\n';
  }
}
