#include <iostream>

using namespace std;

int main() {
  int n, T, t;

  cin >> n >> T;

  int i;
  for (i = 0; i < n; i++) {
    cin >> t;

    if (T < t) {
      cout << i;
      break;
    }

    T -= t;
  }

  if (i == n) {
    cout << n;
  }
}