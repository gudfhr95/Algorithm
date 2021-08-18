#include <iostream>

using namespace std;

int main() {
  int n, a, b, c;

  cin >> n >> a >> b;

  if (n == 3) cin >> c;

  for (int i = 1; i <= a; i++) {
    if (a % i == 0 && b % i == 0 && c % i == 0) cout << i << '\n';
  }
}