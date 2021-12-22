#include <cstring>
#include <iostream>

using namespace std;

int coins[100];
int d[1000000];

int main() {
  int n, k;

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  memset(d, -1, sizeof(d));

  d[0] = 0;
  for (int i = 0; i <= k; i++) {
    if (d[i] == -1) continue;

    for (int j = 0; j < n; j++) {
      if (d[i + coins[j]] == -1) {
        d[i + coins[j]] = d[i] + 1;
      } else {
        d[i + coins[j]] = min(d[i + coins[j]], d[i] + 1);
      }
    }
  }

  cout << d[k];
}
