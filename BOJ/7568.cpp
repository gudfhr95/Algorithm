#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N;
int result[50] = {
    0,
};
vector<pair<int, int>> dc;

int main() {
  pair<int, int> temp;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> temp.first;
    cin >> temp.second;
    dc.push_back(temp);
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (dc[i].first < dc[j].first && dc[i].second < dc[j].second) {
        result[i] += 1;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << result[i] + 1 << '\n';
  }

  return 0;
}