#include <iostream>

using namespace std;

int main() {
  int T, test_case;
  int a, b;
  cin >> T;

  for (int test_case = 0; test_case < T; ++test_case) {
    cin >> a >> b;
    cout << a + b << endl;
  }

  return 0;
}