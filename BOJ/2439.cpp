#include <iostream>

using namespace std;

int main() {
  int n;
  string output;

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    output = "";
    for (int j = 0; j < n - i - 1; j++) {
      output += " ";
    }
    for (int k = 0; k < i + 1; k++) {
      output += "*";
    }
    printf("%s\n", output.c_str());
  }

  return 0;
}