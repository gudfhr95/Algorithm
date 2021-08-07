#include <iostream>

using namespace std;

int main() {
  int T, C;
  long N;

  cin >> T;

  while (T--) {
    cin >> N >> C;

    if (N % C == 0)
      cout << N / C << '\n';
    else
      cout << N / C + 1 << '\n';
  }
}