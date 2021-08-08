#include <iostream>

using namespace std;

int gcd(int n, int m) { return n % m ? gcd(m, n % m) : m; }

int lcm(int n, int m) { return n / gcd(n, m) * m; }

int main() {
  int n, a, b;

  cin >> n;

  while (n--) {
    cin >> a >> b;

    cout << lcm(a, b) << '\n';
  }
}