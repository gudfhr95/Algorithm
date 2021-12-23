#include <iostream>

using namespace std;

long long pow(long long a, long long b, long long c) {
  if (b == 0) {
    return 1;
  } else if (b == 1) {
    return a % c;
  } else if (b % 2 == 0) {
    long long temp = pow(a, b / 2, c) % c;
    return (temp * temp) % c;
  } else {
    return (a * pow(a, b - 1, c)) % c;
  }
}

int main() {
  long long A, B, C;

  cin >> A >> B >> C;

  cout << pow(A, B, C);
}