#include <iostream>

using namespace std;

int main() {
  int T, V, E;

  cin >> T;

  while (T--) {
    cin >> V >> E;
    cout << 2 + E - V << endl;
  }

  return 0;
}