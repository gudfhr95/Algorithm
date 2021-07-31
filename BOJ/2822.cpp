#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }

int main() {
  int score;
  vector<pair<int, int>> scores;

  int result_sum = 0;
  vector<int> result_index;

  for (int i = 1; i <= 8; i++) {
    cin >> score;
    scores.push_back({i, score});
  }

  sort(scores.begin(), scores.end(), cmp);

  for (int i = 0; i < 5; i++) {
    result_index.push_back(scores[i].first);
    result_sum += scores[i].second;
  }

  sort(result_index.begin(), result_index.end());

  cout << result_sum << '\n';

  for (int i = 0; i < 5; i++) {
    cout << result_index[i] << ' ';
  }
}