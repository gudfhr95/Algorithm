#include <iostream>

using namespace std;

int CHANGES[6] = {500, 100, 50, 10, 5, 1};

int main() {
  int n, result = 0;

  cin >> n;
  n = 1000 - n;

  for (int i = 0; i < 6; i++) {
    result += n / CHANGES[i];
    n %= CHANGES[i];
  }

  cout << result;
}
