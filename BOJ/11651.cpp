#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
    return a.second < b.second;
}

int main() {
  int N;
  pair<int, int> p;
  vector<pair<int, int>> coords;

  cin >> N;

  while (N--) {
    cin >> p.first >> p.second;
    coords.push_back(p);
  }

  sort(coords.begin(), coords.end(), cmp);

  for (const auto &elem : coords) {
    cout << elem.first << ' ' << elem.second << '\n';
  }
}