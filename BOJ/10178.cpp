#include <iostream>

using namespace std;

int main() {
  int T, c, v;

  cin >> T;

  while (T--) {
    cin >> c >> v;
    printf("You get %d piece(s) and your dad gets %d piece(s).\n", c / v,
           c % v);
  }

  return 0;
}