#include <iostream>

using namespace std;

int main() {
  int input[10];
  bool result_array[42] = {
      false,
  };
  int result = 0;

  for (int i = 0; i < 10; ++i) {
    scanf("%d", &input[i]);
  }

  for (auto &elem : input) {
    elem %= 42;
  }

  for (const auto &elem : input) {
    result_array[elem] = true;
  }

  for (const auto elem : result_array) {
    result += elem;
  }

  printf("%d", result);
}