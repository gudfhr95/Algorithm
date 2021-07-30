#include <iostream>

using namespace std;

int main() {
  int T;
  char input[80];
  int i, count, result;

  scanf("%d", &T);

  for (int test_case = 0; test_case < T; ++test_case) {
    scanf("%s", input);

    i = 0;
    count = 1;
    result = 0;
    while (input[i] != '\0') {
      if (input[i] == 'O') {
        result += count;
        count += 1;
      }
      if (input[i] == 'X') {
        count = 1;
      }
      ++i;
    }
    printf("%d\n", result);
  }

  return 0;
}