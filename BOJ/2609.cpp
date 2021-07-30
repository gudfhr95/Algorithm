#include <iostream>

using namespace std;

int main() {
  int A, B;
  int gcd, lcm;

  cin >> A >> B;

  for (int i = 1; i <= A * B; i++) {
    if (A % i == 0 && B % i == 0) {
      gcd = i;
    }
    if (i % A == 0 && i % B == 0) {
      lcm = i;
      break;
    }
  }

  cout << gcd << '\n' << lcm;

  return 0;
}