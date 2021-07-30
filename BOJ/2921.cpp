#include <iostream>

using namespace std;

int main() {
  int N, total = 0;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= i; j++) {
      total += i + j;
    }
  }

  cout << total;

  return 0;
}