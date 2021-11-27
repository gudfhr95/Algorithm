#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double x, y, c;

  cin >> x >> y >> c;

  double l = 0;
  double r = min(x, y);
  while (abs(r - l) > 1e-6) {
    double mid = (l + r) / 2;
    double d = mid;

    double h1 = sqrt(x * x - d * d);
    double h2 = sqrt(y * y - d * d);
    double h = (h1 * h2) / (h1 + h2);

    if (h > c) {
      l = mid;
    } else {
      r = mid;
    }
  }

  printf("%.3lf\n", l);
}