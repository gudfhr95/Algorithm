#include <iostream>

using namespace std;

int main() {
  int T, distance;
  string a, b;

  cin >> T;

  while (T--) {
    cin >> a >> b;

    distance = 0;

    for (int i = 0; i < a.length(); i++) {
      if (a[i] != b[i]) distance++;
    }

    printf("Hamming distance is %d.\n", distance);
  }
}