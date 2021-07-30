#include <iostream>

using namespace std;

int main() {
  int K, N, M;
  int money;

  cin >> K >> N >> M;

  money = (K * N - M <= 0) ? 0 : K * N - M;

  cout << money;

  return 0;
}