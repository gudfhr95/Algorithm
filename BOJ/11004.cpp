#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K, n;
  vector<long long> v;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;

  while (N--) {
    cin >> n;
    v.push_back(n);
  }

  sort(v.begin(), v.end());

  cout << v[K - 1];
}
