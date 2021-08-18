#include <iostream>

using namespace std;

int main() {
  int M, X, Y, temp;
  int cup[3] = {1, 0, 0};

  cin >> M;

  while (M--) {
    cin >> X >> Y;

    temp = cup[X - 1];
    cup[X - 1] = cup[Y - 1];
    cup[Y - 1] = temp;
  }

  for (int i = 0; i < 3; i++) {
    if (cup[i] == 1) cout << i + 1;
  }
}