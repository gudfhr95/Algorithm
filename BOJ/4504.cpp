#include <iostream>

using namespace std;

int main() {
  int n, number;

  cin >> n;

  while (true) {
    cin >> number;

    if (number == 0) break;

    if (number % n == 0)
      printf("%d is a multiple of %d.\n", number, n);
    else
      printf("%d is NOT a multiple of %d.\n", number, n);
  }
}