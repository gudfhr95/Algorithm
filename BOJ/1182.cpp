#include <iostream>

using namespace std;

int seq[20];

int main() {
  int N, S;

  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
  }

  int result = 0;
  for (int i = 1; i < (1 << N); i++) {
    int sum = 0;
    for (int k = 0; k < N; k++) {
      if ((i & (1 << k)) != 0) {
        sum += seq[k];
      }
    }

    if (sum == S) result++;
  }

  cout << result;
}