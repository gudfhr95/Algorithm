#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T;
  string s;

  cin >> T;

  while (T--) {
    cin >> s;

    if (!next_permutation(s.begin(), s.end()))
      cout << "BIGGEST\n";
    else
      cout << s << '\n';
  }
}
