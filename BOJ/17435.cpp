#include <iostream>

using namespace std;

int d[200001][20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> d[i][0];
  }

  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      d[i][j] = d[d[i][j - 1]][j - 1];
    }
  }

  int q;

  cin >> q;

  while (q--) {
    int m, x;

    cin >> m >> x;

    for (int i = 0; i < 20; i++) {
      if (m & (1 << i)) {
        x = d[x][i];
      }
    }

    cout << x << '\n';
  }

  return 0;
}
