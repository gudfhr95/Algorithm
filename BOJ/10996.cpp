#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;

  for (int y = 0; y < 2 * N; y++) {
    for (int x = 0; x < N; x++) {
      if ((x + y) % 2 == 0)
        cout << '*';
      else
        cout << ' ';
    }

    cout << '\n';
  }
}