#include <iostream>

using namespace std;

int main() {
  int n;
  int score[5] = {0, 0, 0, 0, 0};
  pair<int, int> max = {-1, -987654321};

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> n;
      score[i] += n;
    }
  }

  for (int i = 0; i < 5; i++) {
    if (score[i] > max.second) {
      max.first = i + 1;
      max.second = score[i];
    }
  }

  cout << max.first << '\n' << max.second;
}