#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const pair<int, string> &a, const pair<int, string> &b) {
  return a.first < b.first;
}

int main() {
  int N;

  cin >> N;

  vector<pair<int, string>> members(N);

  for (int i = 0; i < N; i++) {
    cin >> members[i].first >> members[i].second;
  }

  stable_sort(members.begin(), members.end(), cmp);

  for (const auto &member : members) {
    cout << member.first << ' ' << member.second << '\n';
  }
}