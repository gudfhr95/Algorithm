#include <iostream>

using namespace std;

long long d[101];

int main() {
  int N;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    d[i] = d[i - 1] + 1;

    for (int j = 1; j <= i - 3; j++) {
      d[i] = max(d[i], d[i - j - 2] * (j + 1));
    }
  }

  cout << d[N];
}
