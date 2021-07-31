#include <iostream>

using namespace std;

int main() {
  int n[9];

  for (int i = 0; i < 9; ++i) {
    scanf("%d", &n[i]);
  }

  int max = -987654321;
  int max_index;

  for (int j = 0; j < 9; ++j) {
    if (n[j] > max) {
      max = n[j];
      max_index = j;
    }
  }

  printf("%d\n", max);
  printf("%d", max_index + 1);
  return 0;
}