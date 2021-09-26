#include <iostream>

using namespace std;

char candy[50][50];

int eat(int n) {
  int result = -987654321;

  for (int y = 0; y < n; y++) {
    int temp = 1;
    for (int x = 0; x < n - 1; x++) {
      if (candy[y][x] == candy[y][x + 1]) {
        temp++;
      } else {
        result = max(result, temp);
        temp = 1;
      }
    }
    result = max(result, temp);
  }

  for (int x = 0; x < n; x++) {
    int temp = 1;
    for (int y = 0; y < n - 1; y++) {
      if (candy[y][x] == candy[y + 1][x]) {
        temp++;
      } else {
        result = max(result, temp);
        temp = 1;
      }
    }
    result = max(result, temp);
  }

  return result;
}

int count(int n) {
  int result = -987654321;

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n - 1; x++) {
      swap(candy[y][x], candy[y][x + 1]);
      result = max(result, eat(n));
      swap(candy[y][x], candy[y][x + 1]);
    }
  }

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n - 1; y++) {
      swap(candy[y][x], candy[y + 1][x]);
      result = max(result, eat(n));
      swap(candy[y][x], candy[y + 1][x]);
    }
  }

  return result;
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> candy[i];
  }

  cout << count(N);
}