#include <iostream>

using namespace std;

int d[1500000];

int main() {
  long long n;

  cin >> n;

  d[0] = 0;
  d[1] = 1;
  for (int i = 2; i < 1500000; i++) {
    d[i] = d[i - 1] + d[i - 2];
    d[i] %= 1000000;
  }

  cout << d[n % 1500000];
}