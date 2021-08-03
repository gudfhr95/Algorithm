#include <iostream>

using namespace std;

int getPrice(int* dices) {
  int max = -987654321, max_index;
  bool isSame = false;

  for (int i = 0; i < 6; i++) {
    if (dices[i] >= max) {
      max = dices[i];
      max_index = i;
    }
  }

  if (max == 4)
    return 50000 + ((max_index + 1) * 5000);
  else if (max == 3)
    return 10000 + ((max_index + 1) * 1000);
  else if (max == 2) {
    int sum = 1000 + (max_index + 1) * 100;
    for (int i = 0; i < 6; i++) {
      if (i == max_index) continue;

      if (dices[i] == max) {
        sum += 1000 + (i + 1) * 500 + (max_index + 1) * 400;
        break;
      }
    }
    return sum;
  } else
    return (max_index + 1) * 100;
}

int main() {
  int N, n, result = -987654321;

  cin >> N;

  while (N--) {
    int dices[6] = {
        0,
    };

    for (int i = 0; i < 4; i++) {
      cin >> n;
      dices[n - 1]++;
    }
    result = max(result, getPrice(dices));
  }

  cout << result;
}