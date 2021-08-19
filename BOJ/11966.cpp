#include <iostream>

using namespace std;

bool isPowOfTwo(int n) {
  while (n > 1) {
    if (n % 2 == 1) return false;

    n = n / 2;
  }

  return true;
}

int main() {
  int n;

  cin >> n;

  cout << isPowOfTwo(n);
}