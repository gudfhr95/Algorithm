#include <cstring>
#include <iostream>

using namespace std;

int score[2];

int main() {
  int T;
  int Y, K;

  cin >> T;

  while (T--) {
    memset(score, 0, sizeof(score));
    for (int i = 0; i < 9; ++i) {
      cin >> Y >> K;
      score[0] += Y;
      score[1] += K;
    }
    if (score[0] > score[1]) {
      cout << "Yonsei\n";
    } else if (score[0] == score[1]) {
      cout << "Draw\n";
    } else {
      cout << "Korea";
    }
  }
}