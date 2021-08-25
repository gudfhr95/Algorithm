#include <cmath>
#include <iostream>

using namespace std;

void hanoi(int n, int source, int by, int target) {
  if (n == 1) {
    cout << source << ' ' << target << '\n';
    return;
  } else {
    hanoi(n - 1, source, target, by);
    cout << source << ' ' << target << '\n';
    hanoi(n - 1, by, source, target);
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;

  cin >> N;

  cout << (int)pow(2, N) - 1 << '\n';

  hanoi(N, 1, 2, 3);

  return 0;
}