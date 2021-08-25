#include <iostream>

using namespace std;

long long getPeople(int stops) {
  double result = 1;

  for (int i = 2; i <= stops; i++) {
    result += 0.5;
    result *= 2;
  }

  return (long long)result;
}

int main() {
  int T, k;

  cin >> T;

  while (T--) {
    cin >> k;

    cout << getPeople(k) << '\n';
  }
}
