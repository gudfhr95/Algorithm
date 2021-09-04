#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double N, B, M;

  while (cin >> N >> B >> M) {
    int year = 1;

    while (true) {
      double sum = N * pow((B / 100) + 1, year);

      if (sum > M) {
        break;
      }

      year++;
    }

    cout << year << '\n';
  }
}