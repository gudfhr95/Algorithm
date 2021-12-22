#include <iostream>

using namespace std;

int pages[500];
pair<int, int> d[500][500];

pair<int, int> solve(int start, int end) {
  if (start == end) {
    d[start][start].first = pages[start];
    d[start][start].second = 0;
    return d[start][start];
  }

  pair<int, int>& ret = d[start][end];

  if (ret.first != 0) {
    return ret;
  }

  int minCost = 987654321;
  pair<int, int> minD1;
  pair<int, int> minD2;
  for (int i = 0; i < end - start; i++) {
    auto d1 = solve(start, start + i);
    auto d2 = solve(start + i + 1, end);

    int cost = d1.first + d2.first + d1.second + d2.second;

    if (cost < minCost) {
      minD1 = d1;
      minD2 = d2;
      minCost = cost;
    }
  }

  return ret = {minD1.first + minD2.first, minCost};
}

int main() {
  int T;

  cin >> T;

  while (T--) {
    int K;

    cin >> K;

    for (int i = 0; i < K; i++) {
      cin >> pages[i];

      for(int j=0; j<K; j++){
        d[i][j] = {0, 0};
      }
    }

    auto result = solve(0, K - 1);

    cout << result.second << '\n';
  }
}
