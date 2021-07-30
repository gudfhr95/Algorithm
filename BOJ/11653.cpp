#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;

  int remainer = N;
  int i = 2;

  while (true) {
    if (N == 1) {
      break;
    }
    if (remainer % i == 0) {
      cout << i << '\n';
      remainer /= i;
    } else {
      if (remainer <= i) {
        if (remainer != 1) {
          cout << remainer << '\n';
        }
        break;
      }
      i += 1;
    }
  }

  return 0;
}