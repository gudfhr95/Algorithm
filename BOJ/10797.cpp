#include <iostream>

using namespace std;

int main() {
  int day, n, result = 0;

  cin >> day;

  for (int i = 0; i < 5; i++) {
    cin >> n;
    if (n == day) result++;
  }

  cout << result;
}