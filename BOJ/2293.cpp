#include <iostream>

using namespace std;

int coins[100];
int d[10001];

int main() {
  int n, k;

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  d[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j - coins[i] >= 0) {
        d[j] += d[j - coins[i]];
      }
    }
  }

  //  for (int i = 0; i <= k; i++) {
  //    cout << d[i] << ' ';
  //  }

  cout << d[k];
}
