#include <iostream>

using namespace std;

long long two = 0, five = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, m;

  cin >> n >> m;

  for (long long i = 2; i <= n; i *= 2) {
    two += n / i;
  }

  for (long long i = 2; i <= n - m; i *= 2) {
    two -= (n - m) / i;
  }

  for (long long i = 2; i <= m; i *= 2) {
    two -= m / i;
  }

  for (long long i = 5; i <= n; i *= 5) {
    five += n / i;
  }

  for (long long i = 5; i <= n - m; i *= 5) {
    five -= (n - m) / i;
  }

  for (long long i = 5; i <= m; i *= 5) {
    five -= m / i;
  }

  cout << min(two, five);
}