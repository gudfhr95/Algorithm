#include <iostream>

using namespace std;

int main() {
  int T, A, B;
  int i;

  cin >> T;

  while (T--) {
    cin >> A >> B;
    i = 1;
    while (true) {
      if ((A * i) % B == 0) {
        break;
      }
      i++;
    }
    cout << (A * i) << '\n';
  }
}