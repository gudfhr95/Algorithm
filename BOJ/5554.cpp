#include <iostream>

using namespace std;

int main() {
  int n, total = 0;

  for (int i = 0; i < 4; i++) {
    cin >> n;

    total += n;
  }
  cout << total / 60 << '\n';
  cout << total % 60;
}