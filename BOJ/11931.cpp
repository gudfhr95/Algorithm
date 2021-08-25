#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n;
  vector<long long> v;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  while (N--) {
    cin >> n;
    v.push_back(n);
  }

  sort(v.begin(), v.end(), greater<>());

  for (const auto &elem : v) {
    cout << elem << '\n';
  }
}
