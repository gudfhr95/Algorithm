#include <iostream>

using namespace std;

bool d[401][401];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;

  cin >> n >> k;

  int a, b;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;

    d[a][b] = true;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (d[i][k] && d[k][j]) {
          d[i][j] = true;
        }
      }
    }
  }

  int s;

  cin >> s;

  for (int i = 0; i < s; i++) {
    cin >> a >> b;

    if (d[a][b]) {
      cout << -1 << '\n';
    } else if (d[b][a]) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
}