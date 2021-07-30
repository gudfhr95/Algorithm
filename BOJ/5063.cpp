#include <iostream>

using namespace std;

int main() {
  int N;
  int r, e, c;

  cin >> N;

  while (N--) {
    cin >> r >> e >> c;

    if (e - r == c) {
      cout << "does not matter\n";
    }
    if (e - r > c) {
      cout << "advertise\n";
    }
    if (e - r < c) {
      cout << "do not advertise\n";
    }
  }

  return 0;
}