#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, i, j;
  vector<int> baskets;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    baskets.push_back(i);
  }

  while (M--) {
    cin >> i >> j;

    reverse(baskets.begin() + i - 1, baskets.begin() + j);
  }

  for (const auto &elem : baskets) {
    cout << elem << ' ';
  }
}