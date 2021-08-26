#include <iostream>

using namespace std;

int gcd(int a, int b) { return (a % b == 0 ? b : gcd(b, a % b)); }

int main() {
  int N, r, n;

  cin >> N >> r;

  for (int i = 1; i < N; i++) {
    cin >> n;

    printf("%d/%d\n", r / gcd(r, n), n / gcd(r, n));
  }
}