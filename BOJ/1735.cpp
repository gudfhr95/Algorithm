#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
  return a % b == 0 ? b : gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

int main() {
  long long a1, a2, b1, b2;

  cin >> a1 >> a2 >> b1 >> b2;

  long long denominator = lcm(a2, b2);

  long long a_numerator = a1 * denominator / a2;
  long long b_numerator = b1 * denominator / b2;

  long long numerator = a_numerator + b_numerator;

  cout << numerator / gcd(numerator, denominator) << ' '
       << denominator / gcd(numerator, denominator);
}
