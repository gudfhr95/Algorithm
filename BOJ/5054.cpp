#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, n, pos;

  cin >> t;

  while (t--) {
    vector<int> stores;

    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> pos;
      stores.push_back(pos);
    }

    sort(stores.begin(), stores.end(), greater<>());

    cout << (stores.front() - stores.back()) * 2 << '\n';
  }
}