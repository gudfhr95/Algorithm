#include <iostream>
#include <vector>

using namespace std;

bool isOne(int n) {
  if (n < 100) {
    return true;
  }

  int a = n / 100;
  int b = (n % 100) / 10;
  int c = n % 10;

  if ((a - b) == (b - c)) {
    return true;
  }

  return false;
}

int main() {
  int N;
  int result = 0;

  cin >> N;

  for (int i = 1; i <= N; ++i) {
    if (isOne(i)) {
      result++;
    }
  }

  cout << result << '\n';
  return 0;
}