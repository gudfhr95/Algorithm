#include <iostream>

using namespace std;

int main() {
  int temp;
  int result = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> temp;
    result += (temp < 40) ? 40 : temp;
  }
  cout << result / 5;
}