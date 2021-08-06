#include <iostream>

using namespace std;

int main() {
  int N, K, result = 1;

  cin >> N >> K;

  for (int i = K + 1; i <= N; i++) {
    result *= i;
  }

  for (int i = 1; i <= (N - K); i++) {
    result /= i;
  }

  cout << result;
}