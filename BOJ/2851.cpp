#include <iostream>

using namespace std;

int main() {
  int mushrooms[10];

  for (int i = 0; i < 10; i++) {
    cin >> mushrooms[i];
  }

  int result = 0;
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    int temp_sum = sum + mushrooms[i];
    if (abs(temp_sum - 100) <= abs(result - 100)) {
      result = temp_sum;
    }
    sum = temp_sum;
  }

  cout << result;
}