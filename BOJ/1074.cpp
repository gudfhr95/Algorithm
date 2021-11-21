#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int N, r, c;

  cin >> N >> r >> c;

  int result = 0;
  while (true) {
    if (N == 0) break;

    int n = pow(2, N - 1);

    if (r < n && c < n) {
      result += 0;
    } else if (r < n && c >= n) {
      result += n * n;
      c -= n;
    } else if (r >= n && c < n) {
      result += n * n * 2;
      r -= n;
    } else {
      result += n * n * 3;
      r -= n;
      c -= n;
    }

    N -= 1;
  }

  cout << result;
}