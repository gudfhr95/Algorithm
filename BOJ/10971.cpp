#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int c[10][10];

int getTotalCost(vector<int> path) {
  int result = 0;

  path.push_back(path[0]);

  for (int i = 0; i < path.size() - 1; i++) {
    if (c[path[i]][path[i + 1]] == 0) return 987654321;

    result += c[path[i]][path[i + 1]];
  }

  return result;
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> c[i][j];
    }
  }

  vector<int> path;
  for (int i = 0; i < N; i++) {
    path.push_back(i);
  }

  int result = 987654321;
  do {
    result = min(result, getTotalCost(path));
  } while (next_permutation(path.begin(), path.end()));

  cout << result;
}