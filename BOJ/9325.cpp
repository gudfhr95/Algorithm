#include <iostream>

using namespace std;

int main() {
  int T, s, n, q, p;

  cin >> T;

  while (T--) {
    cin >> s >> n;

    for (int i = 0; i < n; i++) {
      cin >> q >> p;
      s += q * p;
    }

    cout << s << endl;
  }

  return 0;
}