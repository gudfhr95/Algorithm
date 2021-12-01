#include <iostream>

using namespace std;

int main() {
  int A, B, C, X, Y;

  cin >> A >> B >> C >> X >> Y;

  long long result = 50000000000LL;
  for (int i = 0; i <= max(X, Y); i++) {
    long long fried = max(X - i, 0);
    long long sauced = max(Y - i, 0);
    long long sum = (A * fried) + (B * sauced) + (2 * C * i);
    result = min(result, sum);
  }

  cout << result;
}