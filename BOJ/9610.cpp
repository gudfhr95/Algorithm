#include <iostream>

using namespace std;

int result[5] = {
    0,
};

int main() {
  int n;
  int x, y;
  int x_index, y_index;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    if (x == 0 || y == 0) {
      result[4]++;
    } else if (x > 0 && y > 0) {
      result[0]++;
    } else if (x < 0 && y > 0) {
      result[1]++;
    } else if (x < 0 && y < 0) {
      result[2]++;
    } else if (x > 0 && y < 0) {
      result[3]++;
    }
  }

  for (int i = 0; i < 4; ++i) {
    printf("Q%d: %d\n", i + 1, result[i]);
  }
  printf("AXIS: %d", result[4]);
}