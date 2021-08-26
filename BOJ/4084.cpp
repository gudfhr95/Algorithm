#include <iostream>

using namespace std;

void count(int a, int b, int c, int d) {
  int count = 0;
  while (true) {
    int a_temp = abs(a - b);
    int b_temp = abs(b - c);
    int c_temp = abs(c - d);
    int d_temp = abs(d - a);

    a = a_temp;
    b = b_temp;
    c = c_temp;
    d = d_temp;

    if (a == 0 && b == 0 && c == 0 && d == 0) break;

    count++;
  }

  cout << count << '\n';
}

int main() {
  int a, b, c, d;

  while (true) {
    cin >> a >> b >> c >> d;

    if (a == 0 && b == 0 && c == 0 && d == 0) break;

    count(a, b, c, d);
  }
}