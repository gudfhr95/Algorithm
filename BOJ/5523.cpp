#include <iostream>

using namespace std;

int main() {
  int N;
  int a, b, a_total = 0, b_total = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    if (a > b)
      a_total++;
    else if (a < b)
      b_total++;
  }

  cout << a_total << ' ' << b_total;
}