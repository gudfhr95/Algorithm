#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  vector<int> divisors;

  for (int i = a; i >= 1; i--) {
    if (a % i == 0) divisors.push_back(i);
  }

  for (const auto &elem : divisors) {
    if (b % elem == 0) return elem;
  }
}

int lcm(int a, int b) {
  int i = 1;
  while (true) {
    if ((a * i) % b == 0) return (a * i);
    i++;
  }
}

int main() {
  int T, a, b;

  cin >> T;

  while (T--) {
    cin >> a >> b;

    printf("%d %d\n", lcm(a, b), gcd(a, b));
  }
}