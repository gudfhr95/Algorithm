#include <iostream>

using namespace std;

int a[1025][1025];
int s[1025][1025];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  }

  while (M--) {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]
         << '\n';
  }
}