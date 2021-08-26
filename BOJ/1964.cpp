#include <iostream>

using namespace std;

int main() {
  long long N;

  cin >> N;

  long long dots = 5;
  for (long long i = 2; i <= N; i++) {
    dots += (3 * i) + 1;
  }

  cout << dots % 45678;
}