#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int a[3];
  int temp;

  while (true) {
    cin >> a[0] >> a[1] >> a[2];
    if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0)) {
      break;
    }

    for (int i = 0; i < 2; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        if (a[i] <= a[j]) {
          temp = a[j];
          a[j] = a[i];
          a[i] = temp;
        }
      }
    }

    if (pow(a[0], 2) == (pow(a[1], 2) + pow(a[2], 2))) {
      cout << "right\n";
    } else {
      cout << "wrong\n";
    }
  }
  return 0;
}