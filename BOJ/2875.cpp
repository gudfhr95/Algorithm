#include <iostream>

using namespace std;

int main() {
  int N, M, K;

  cin >> N >> M >> K;

  int teams = min(N / 2, M);

  N -= teams * 2;
  M -= teams;

  while (true) {
    if (N + M >= K) {
      cout << teams;
      break;
    }

    N += 2;
    M += 1;
    teams -= 1;
  }
}