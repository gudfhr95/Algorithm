#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }

void check_winner(vector<pair<int, int>> votes, int v_total) {
  sort(votes.begin(), votes.end(), cmp);

  bool hasWinner = (votes[0].second != votes[1].second) ? true : false;

  if (hasWinner) {
    if (votes[0].second > v_total / 2)
      cout << "majority winner " << votes[0].first << '\n';
    else
      cout << "minority winner " << votes[0].first << '\n';
  } else {
    cout << "no winner\n";
  }
}

int main() {
  int T, n, v;

  cin >> T;

  while (T--) {
    cin >> n;

    vector<pair<int, int>> votes;
    int v_total = 0;

    for (int i = 1; i <= n; i++) {
      cin >> v;
      votes.push_back({i, v});
      v_total += v;
    }

    check_winner(votes, v_total);
  }
}
