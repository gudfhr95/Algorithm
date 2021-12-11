#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> candidate) {
  for (int y = 0; y < 3; y++) {
    int sum = 0;
    for (int x = 0; x < 3; x++) {
      sum += candidate[y * 3 + x];
    }

    if (sum != 15) {
      return false;
    }
  }

  for (int x = 0; x < 3; x++) {
    int sum = 0;
    for (int y = 0; y < 3; y++) {
      sum += candidate[y * 3 + x];
    }
    if (sum != 15) {
      return false;
    }
  }

  if (candidate[0] + candidate[4] + candidate[8] != 15) return false;

  if (candidate[6] + candidate[4] + candidate[2] != 15) return false;

  return true;
}

int main() {
  vector<int> square(9);

  for (int i = 0; i < 9; i++) {
    cin >> square[i];
  }

  vector<int> candidate = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int result = 987654321;
  do {
    if (check(candidate)) {
      int sum = 0;
      for (int i = 0; i < 9; i++) {
        sum += abs(square[i] - candidate[i]);
      }
      result = min(result, sum);
    }
  } while (next_permutation(candidate.begin(), candidate.end()));

  cout << result;
}