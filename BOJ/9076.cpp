#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T, s;
  vector<int> scores;

  cin >> T;

  while (T--) {
    scores.clear();

    for (int i = 0; i < 5; i++) {
      cin >> s;
      scores.push_back(s);
    }

    sort(scores.begin(), scores.end());

    if (scores[3] - scores[1] >= 4)
      cout << "KIN" << '\n';
    else
      cout << scores[1] + scores[2] + scores[3] << '\n';
  }
}