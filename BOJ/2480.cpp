#include <iostream>

using namespace std;

int dice[6] = {
    0,
};

int main() {
  int A, B, C;
  int max;

  cin >> A >> B >> C;

  dice[A - 1]++;
  dice[B - 1]++;
  dice[C - 1]++;

  for (int i = 0; i < 6; ++i) {
    if (dice[i] == 3) {
      cout << 10000 + (i + 1) * 1000;
      return 0;
    } else if (dice[i] == 2) {
      cout << 1000 + (i + 1) * 100;
      return 0;
    } else if (dice[i] == 1) {
      max = i;
    }
  }

  cout << (max + 1) * 100;

  return 0;
}