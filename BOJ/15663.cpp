#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int seq[8];
bool c[8];
int a[8];

set<vector<int>> result;

void permutation(int index, int n, int m) {
  if (index == m) {
    vector<int> temp;

    for (int i = 0; i < m; i++) {
      temp.push_back(a[i]);
    }

    result.insert(temp);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (c[i]) continue;

    c[i] = true;

    a[index] = seq[i];
    permutation(index + 1, n, m);
    c[i] = false;
  }
}

int main() {
  int N, M;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
  }

  sort(seq, seq + N);

  permutation(0, N, M);

  for (const auto &v : result) {
    for (const auto &e : v) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}