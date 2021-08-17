#include <iostream>

using namespace std;

bool isArithmetic(int a1, int a2, int a3) {
  if (a1 - a2 == a2 - a3)
    return true;
  else
    return false;
}

int main() {
  int a1, a2, a3;

  while (true) {
    cin >> a1 >> a2 >> a3;

    if (a1 == 0 && a2 == 0 && a3 == 0) break;

    if (isArithmetic(a1, a2, a3))
      cout << "AP " << a3 + (a2 - a1) << '\n';
    else
      cout << "GP " << a3 * (a2 / a1) << '\n';
  }
}