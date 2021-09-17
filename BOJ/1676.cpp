#include <iostream>

using namespace std;

int two = 0, five = 0;

void getTwoOrFive(int n) {
  while (n % 2 == 0) {
    n /= 2;
    two++;
  }
  while (n % 5 == 0) {
    n /= 5;
    five++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    getTwoOrFive(i);
  }

  cout << min(two, five);
}