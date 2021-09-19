#include <iostream>

using namespace std;

int main() {
  int M, N;

  cin >> M >> N;

  bool* PrimeArray = new bool[N + 1];

  for (int i = 2; i <= N; ++i) {
    PrimeArray[i] = true;
  }

  for (int i = 2; i * i <= N; ++i) {
    if (PrimeArray[i]) {
      for (int j = i * 2; j <= N; j += i) {
        PrimeArray[j] = false;
      }
    }
  }

  for (int i = M; i <= N; ++i) {
    if (PrimeArray[i]) {
      cout << i << '\n';
    }
  }

  return 0;
}