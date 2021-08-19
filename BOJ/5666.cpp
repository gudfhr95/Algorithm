#include <iostream>

using namespace std;

int main() {
  int H, P;

  while (cin >> H >> P) {
    printf("%.2f\n", (float)H / P);
  }
}