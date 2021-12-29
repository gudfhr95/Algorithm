#include <iostream>

using namespace std;

char a[20][20];
int d[20][20];

const int inf = 100000000;

int main() {
  int n, m;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = '0';
      d[i][j] = inf;
    }
    d[i][i] = 0;
  }

  while (m--) {
    int from, to;
    char cost;

    cin >> from >> to >> cost;

    a[from][to] = cost;
    a[to][from] = cost;
    d[from][to] = 1;
    d[to][from] = 1;
  }

  for (int l = 2; l <= 400; l++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // i -> ... -> j
        if (d[i][j] != inf) {
          for (int ii = 0; ii < n; ii++) {
            for (int jj = 0; jj < n; jj++) {
              // ii -> i -> ... -> j -> jj
              if (a[ii][i] == '0' || a[j][jj] == '0') {
                continue;
              }

              if (a[ii][i] == a[j][jj]) {
                d[ii][jj] = min(d[ii][jj], 2 + d[i][j]);
              }
            }
          }
        }
      }
    }
  }

  if (d[0][1] >= inf) {
    cout << -1 << '\n';
  } else {
    cout << d[0][1] << '\n';
  }

  return 0;
}