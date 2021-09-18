#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) { return (a % b == 0) ? b : gcd(b, a % b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;

  cin >> t;

  while (t--) {
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
      cin >> numbers[i];
    }

    vector<bool> temp(n, false);
    for (int i = 0; i < 2; i++) {
      temp[i] = true;
    }

    long long result = 0;
    do {
      vector<int> comb;
      for (int i = 0; i < n; i++) {
        if (temp[i]) comb.push_back(numbers[i]);
      }

      result += gcd(comb[0], comb[1]);
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << result << '\n';
  }
}