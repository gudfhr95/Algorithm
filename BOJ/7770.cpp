#include <cmath>
#include <iostream>

using namespace std;

int main() {
  long long n;

  cin >> n;

  long long height = 1;
  while (true) {
    long long blocks;
    if (height == 1) {
      blocks = 1;
    } else {
      blocks = (pow((height * 2 - 1), 2) / 2) + 1;
    }

    n -= blocks;

    if (n < 0) {
      cout << height - 1;
      break;
    }

    height++;
  }
}