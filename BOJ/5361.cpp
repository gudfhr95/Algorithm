#include <iostream>

using namespace std;

float PRICE[5] = {350.34, 230.90, 190.55, 125.30, 180.90};

int main() {
  int T, n;
  double result;

  cin >> T;

  while (T--) {
    result = 0;

    for (int i = 0; i < 5; i++) {
      cin >> n;

      result += n * PRICE[i];
    }

    printf("$%.2f\n", result);
  }
}