#include <iostream>

using namespace std;

int main() {
  int t, n, p1_score, p2_score;
  char p1, p2;

  cin >> t;

  while (t--) {
    cin >> n;

    p1_score = p2_score = 0;

    for (int i = 0; i < n; i++) {
      cin >> p1 >> p2;
      if (p1 == p2) continue;

      switch (p1) {
        case 'R':
          if (p2 == 'S')
            p1_score++;
          else
            p2_score++;
          break;
        case 'S':
          if (p2 == 'P')
            p1_score++;
          else
            p2_score++;
          break;
        case 'P':
          if (p2 == 'R')
            p1_score++;
          else
            p2_score++;
          break;
      }
    }

    if (p1_score > p2_score)
      cout << "Player 1\n";
    else if (p1_score < p2_score)
      cout << "Player 2\n";
    else
      cout << "TIE\n";
  }
}