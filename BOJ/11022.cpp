#include <iostream>

using namespace std;

int main() {
  int T, A, B;
  cin >> T;

  for (int i = 1; i <= T; i++) {
    scanf("%d %d", &A, &B);
    printf("Case #%d: %d + %d = %d\n", i, A, B, A + B);
  }
}