#include <iostream>
using namespace std;

int main() {
  int result[10] = {
      0,
  };
  int a, b, c;
  int index;
  string multiple;

  for (int i = 0; i < 3; ++i) {
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
  }

  multiple = to_string(a * b * c);

  for (int j = 0; j < multiple.length(); ++j) {
    index = multiple.at(j) - '0';
    result[index] += 1;
  }

  for (const auto &elem : result) {
    printf("%d\n", elem);
  }
}