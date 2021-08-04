#include <iostream>

using namespace std;

int NUMBERS[2001] = {
    0,
};

int main() {
  int N, n;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> n;
    NUMBERS[n + 1000]++;
  }

  for (int i = 0; i < 2001; i++) {
    if (NUMBERS[i] != 0) cout << i - 1000 << ' ';
  }
}