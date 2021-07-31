#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int in, out, total = 0, max = 0;

  for (int i = 0; i < 4; i++) {
    cin >> out >> in;
    total = clamp(total + in - out, 0, 10000);
    if (total > max) max = total;
  }

  cout << max;
}