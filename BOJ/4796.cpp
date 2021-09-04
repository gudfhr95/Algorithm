#include <iostream>

using namespace std;

int main() {
  int L, P, V;

  int count = 1;
  while (true) {
    cin >> L >> P >> V;

    if (L == 0 && P == 0 && V == 0) break;

    int times = V / P;
    int remainder = min(V % P, L);

    printf("Case %d: %d\n", count, (times * L) + remainder);

    count++;
  }
}