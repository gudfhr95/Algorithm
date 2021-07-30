#include <iostream>

using namespace std;

int main() {
  int x, y;
  int* x_array = new int[1001];
  int* y_array = new int[1001];

  for (int i = 0; i < 3; ++i) {
    cin >> x >> y;
    x_array[x] += 1;
    y_array[y] += 1;
  }

  for (int i = 1; i <= 1000; ++i) {
    if (x_array[i] == 1) {
      x = i;
    }
    if (y_array[i] == 1) {
      y = i;
    }
  }

  cout << x << ' ' << y;

  return 0;
}