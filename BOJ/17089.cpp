#include <iostream>
#include <vector>

using namespace std;

int N, M;
int matrix[4001][4001];
vector<int> adj[4001];

int main() {
  cin >> N >> M;

  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;

    matrix[a][b] = true;
    matrix[b][a] = true;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int result = -1;
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (!matrix[i][j]) continue;

      for (const auto &k : adj[i]) {
        if (k == i || k == j) continue;

        if (!matrix[i][k] || !matrix[j][k]) continue;

        int sum = adj[i].size() + adj[j].size() + adj[k].size() - 6;
        if (result == -1) {
          result = sum;
        } else {
          result = min(result, sum);
        }
      }
    }
  }

  cout << result;
}
