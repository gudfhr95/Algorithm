#include <iostream>

using namespace std;

int main() {
  int total, result;
  int prices[9];

  cin >> total;
  result = total;
  for (int i = 0; i < 9; i++) {
    cin >> prices[i];
  }

  for (int i = 0; i < 9; i++) {
    result -= prices[i];
  }

  cout << result;

  return 0;
}