#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int T, p1, p2, p3, p4, p5, p6, p7;
  int result = 0;

  cin >> T;

  while (T--) {
    cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7;

    result = 0;

    result += (int)(9.23076 * pow(26.7 - p1, 1.835));
    result += (int)(1.84523 * pow(p2 - 75, 1.348));
    result += (int)(56.0211 * pow(p3 - 1.5, 1.05));
    result += (int)(4.99087 * pow(42.5 - p4, 1.81));
    result += (int)(0.188807 * pow(p5 - 210, 1.41));
    result += (int)(15.9803 * pow(p6 - 3.8, 1.04));
    result += (int)(0.11193 * pow(254 - p7, 1.88));

    cout << result << '\n';
  }
}
