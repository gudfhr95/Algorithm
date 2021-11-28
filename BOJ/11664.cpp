#include <cmath>
#include <iostream>

using namespace std;

double ax, ay, az, bx, by, bz, cx, cy, cz;

double dist(double m) {
  double x = ax + ((bx - ax) * m);
  double y = ay + ((by - ay) * m);
  double z = az + ((bz - az) * m);

  return sqrt(pow(cx - x, 2) + pow(cy - y, 2) + pow(cz - z, 2));
}

int main() {
  cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;

  double l = 0.0, r = 1.0;

  while (true) {
    if (abs(l - r) < 1e-9) {
      printf("%.10f", dist((l + r) / 2));
      break;
    }
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    if (dist(m1) > dist(m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }
}