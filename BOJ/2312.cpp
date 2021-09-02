#include <iostream>

using namespace std;

int main() {
  int N, n;

  cin >> N;

  while (N--) {
    cin >> n;

    for (int i = 2; i <= n; i++) {
      int count = 0;

      while (n % i == 0) {
        count++;
        n /= i;
      }

      if (count != 0) cout << i << ' ' << count << '\n';
    }
  }
}