#include <iostream>

using namespace std;

int dice[6] = {
    0,
};

int getPrice(int A, int B, int C) {
  int dice[6] = {
      0,
  };
  int max;

  dice[A - 1]++;
  dice[B - 1]++;
  dice[C - 1]++;

  for (int i = 0; i < 6; ++i) {
    if (dice[i] == 3) {
      return 10000 + (i + 1) * 1000;
    } else if (dice[i] == 2) {
      return 1000 + (i + 1) * 100;
    } else if (dice[i] == 1) {
      max = i;
    }
  }

  return (max + 1) * 100;
}

int main() {
  int N;
  int A, B, C;
  int maxPrice = -987654321;

  cin >> N;

  while (N--) {
    cin >> A >> B >> C;
    maxPrice = max(maxPrice, getPrice(A, B, C));
  }

  cout << maxPrice;

  return 0;
}