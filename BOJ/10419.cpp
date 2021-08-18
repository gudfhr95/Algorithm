#include <cmath>
#include <iostream>

using namespace std;

int getLateTime(int d) {
  int i = 0;
  while (true) {
    if (pow(i, 2) + i > d) return i - 1;
    i++;
  }
}

int main() {
  int T, d;

  cin >> T;

  while (T--) {
    cin >> d;
    cout << getLateTime(d) << '\n';
  }
}