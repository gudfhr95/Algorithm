#include <iostream>
using namespace std;

int a[16];
bool d[81][81][81][81];

int main() {
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  d[0][0][0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int l1 = 80; l1 >= 0; l1--) {
      for (int l2 = 80; l2 >= 0; l2--) {
        for (int l3 = 80; l3 >= 0; l3--) {
          for (int l4 = 80; l4 >= 0; l4--) {
            if (d[l1][l2][l3][l4] == false) {
              continue;
            }

            if (l1 + a[i] <= 80) {
              d[l1 + a[i]][l2][l3][l4] = true;
            }

            if (l2 + a[i] <= 80) {
              d[l1][l2 + a[i]][l3][l4] = true;
            }

            if (l3 + a[i] <= 80) {
              d[l1][l2][l3 + a[i]][l4] = true;
            }

            if (l4 + a[i] <= 80) {
              d[l1][l2][l3][l4 + a[i]] = true;
            }
          }
        }
      }
    }
  }

  int ans = -1;
  for (int i = 1; i <= 80; i++) {
    for (int j = 1; j <= 80; j++) {
      if (d[i][i][j][j]) {
        if (i * j > ans) {
          ans = i * j;
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
