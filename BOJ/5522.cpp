#include <iostream>

using namespace std;

int main() {
  int A, result = 0;

  for (int i = 0; i < 5; i++) {
    cin >> A;
    result += A;
  }

  cout << result;

  return 0;
}