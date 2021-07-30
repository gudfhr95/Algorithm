#include <iostream>

using namespace std;

int main() {
  int start;
  cin >> start;

  for (int i = 1; i < 10; ++i) {
    cout << start << " * " << i << " = " << start * i << endl;
  }

  return 0;
}