#include <iostream>

using namespace std;

int main() {
  int n0, n1, n2, n3, index = 1;

  while (true) {
    cin >> n0;

    if (n0 == 0) break;

    n1 = 3 * n0;

    if (n1 % 2 == 0) {
      printf("%d. even ", index);
      n2 = n1 / 2;
    } else {
      printf("%d. odd ", index);
      n2 = (n1 + 1) / 2;
    }

    n3 = n2 * 3;

    cout << n3 / 9 << '\n';

    index++;
  }
}