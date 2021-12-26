#include <iostream>

using namespace std;

const int INF = 987654321;

int V, E;
int d[401][401];

int main() {
  cin >> V >> E;

  for (int i = 1; i <= V; i++) {
    for (int j = 1; j <= V; j++) {
      d[i][j] = INF;
    }
  }

  int a, b, c;
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;

    d[a][b] = c;
  }

  for (int k = 1; k <= V; k++) {
    for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++) {
        if (d[i][k] == INF || d[k][j] == INF) continue;

        int cost = d[i][k] + d[k][j];
        if (d[i][j] > cost) {
          d[i][j] = cost;
        }
      }
    }
  }

  int result = -1;
  for (int i = 1; i <= V; i++) {
    if (d[i][i] == INF) continue;

    if (result == -1 || result > d[i][i]) {
      result = d[i][i];
    }
  }

  cout << result;
}