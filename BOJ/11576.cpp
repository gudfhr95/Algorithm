#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B, m, n;

  int base10 = 0;

  cin >> A >> B >> m;

  for (int i = 1; i <= m; i++) {
    cin >> n;
    base10 += n * pow(A, m - i);
  }

  vector<int> result;
  while (base10 > 0) {
    result.push_back(base10 % B);
    base10 /= B;
  }

  for (int i = result.size() - 1; i >= 0; i--) {
    cout << result[i] << ' ';
  }
}