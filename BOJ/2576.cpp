#include <iostream>

using namespace std;

int main() {
  int n, sum = 0, min = 987654321;
  for (int i = 0; i < 7; i++) {
    cin >> n;
    if (n % 2 == 1) {
      sum += n;
      if (n < min) {
        min = n;
      }
    }
  }
  if (sum == 0)
    cout << -1;
  else
    cout << sum << '\n' << min;
}