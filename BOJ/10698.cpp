#include <iostream>

using namespace std;

int main() {
  int T, X, Y, result;
  char op, eq;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    cin >> X >> op >> Y >> eq >> result;

    printf("Case %d: ", i);

    if (op == '+') {
      if (X + Y == result)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (X - Y == result)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}