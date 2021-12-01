#include <iostream>

using namespace std;

int N;
int can[1001];

bool check(int n) {
  for (int i = 0; i <= 20; i++) {
    for (int j = 0; j <= 20; j++) {
      for (int k = 0; k <= 20; k++) {
        for (int l = 0; l <= 20; l++) {
          int sum = i + (j * 5) + (k * 10) + (l * 50);
          if (sum == n && (i + j + k + l) == N) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  cin >> N;

  for (int i = 0; i <= 1000; i++) {
    if (check(i)) {
      can[i] = 1;
    }
  }

  int result = 0;
  for (int i = 0; i <= 1000; i++) {
    result += can[i];
  }

  cout << result;
}