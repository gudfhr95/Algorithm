#include <iostream>

using namespace std;

int main() {
  long long N;

  cin >> N;

  long long result = 0;
  for (int i = 1; i < N; i++) {
    result += (N * i) + i;
  }

  cout << result;
}