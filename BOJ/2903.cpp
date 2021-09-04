#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;

  int points = 2;
  for (int i = 1; i <= N; i++) {
    points *= 2;
    points -= 1;
  }

  cout << points * points;
}