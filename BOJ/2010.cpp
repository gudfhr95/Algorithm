#include <iostream>

using namespace std;

int main() {
  int N, m, result = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> m;
    result += m - 1;
  }

  cout << result + 1;

  return 0;
}