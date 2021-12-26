#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool d[111][111];

int main() {
  int n;

  cin >> n;

  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'Y' && a[j][i] == 'N') {
        d[i][j] = true;
      }
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] && d[k][j]) {
          d[i][j] = true;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (d[i][i]) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";

  return 0;
}