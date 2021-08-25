#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool cmp(pair<long long, int> &a, pair<long long, int> &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }

  return a.second > b.second;
}

int main() {
  int N;
  long long n;
  map<long long, int> m;

  cin >> N;

  while (N--) {
    cin >> n;
    m[n]++;
  }

  vector<pair<long long, int>> v(m.begin(), m.end());
  sort(v.begin(), v.end(), cmp);

  cout << v[0].first;
}
