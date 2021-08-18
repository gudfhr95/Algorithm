#include <iostream>

using namespace std;

int main() {
  int T;
  long long n, m;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    cin >> n >> m;

    long long result = (m + n) * (m - n + 1) / 2;

    printf("Scenario #%d:\n%lld\n\n", i, result);
  }
}