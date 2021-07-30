#include <iostream>

using namespace std;

int main() {
  int T, N, C, C_total;
  float G, G_total;

  cin >> T;

  while (T--) {
    cin >> N;
    C_total = 0;
    G_total = 0;

    for (int i = 0; i < N; i++) {
      cin >> C >> G;
      C_total += C;
      G_total += G * C;
    }

    printf("%d %.1f\n", C_total, G_total / C_total);
  }
}