#include <iostream>

using namespace std;

int main() {
  int x, y, w, h;

  cin >> x >> y >> w >> h;

  int x_min = (x <= (w / 2)) ? x : (w - x);
  int y_min = (y <= (h / 2)) ? y : (h - y);
  cout << ((x_min <= y_min) ? x_min : y_min);

  return 0;
}