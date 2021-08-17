#include <cmath>
#include <iostream>

using namespace std;

int getPeopleNum(int a, int b) {
  int sum = 0;
  if (b == 1) {
    return 1;
  }
  if (a == 0) {
    return b;
  }

  for (int i = 1; i <= b; ++i) {
    sum += getPeopleNum(a - 1, i);
  }

  return sum;
}
int main() {
  int T;
  int k, n;

  cin >> T;

  for (int test_case = 0; test_case < T; ++test_case) {
    cin >> k >> n;
    cout << getPeopleNum(k, n) << '\n';
  }

  return 0;
}