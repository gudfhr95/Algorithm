#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;

  cin >> N >> M;

  vector<int> v;
  for (int i = 1; i <= N; i++) {
    v.push_back(i);
  }

  do {
    for (int i = 0; i < M; i++) {
      cout << v[i] << ' ';
    }
    cout << '\n';

    reverse(v.begin() + M, v.end());
  } while (next_permutation(v.begin(), v.end()));
}