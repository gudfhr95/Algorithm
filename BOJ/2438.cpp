#include <iostream>

using namespace std;

int main() {
  int n;
  string star = "*";

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    printf("%s\n", star.c_str());
    star = star + "*";
  }

  return 0;
}