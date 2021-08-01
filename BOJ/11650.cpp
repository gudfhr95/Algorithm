#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
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