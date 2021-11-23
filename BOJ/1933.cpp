#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Building {
  int left, right, height;
};

void append(vector<pair<int, int>> &result, pair<int, int> p) {
  int n = result.size();

  if (n > 0) {
    if (result[n - 1].second == p.second) {
      return;
    }
    if (result[n - 1].first == p.first) {
      result[n - 1].second = p.second;
      return;
    }
  }
  result.push_back(p);
}

vector<pair<int, int>> merge(vector<pair<int, int>> &l,
                             vector<pair<int, int>> &r) {
  vector<pair<int, int>> result;

  int h1 = 0, h2 = 0;
  int i = 0, j = 0;
  while (i < l.size() && j < r.size()) {
    pair<int, int> &u = l[i];
    pair<int, int> &v = r[j];

    if (u.first < v.first) {
      int x = u.first;
      h1 = u.second;
      int h = max(h1, h2);
      append(result, make_pair(x, h));
      i += 1;
    } else {
      int x = v.first;
      h2 = v.second;
      int h = max(h1, h2);
      append(result, make_pair(x, h));
      j += 1;
    }
  }

  while (i < l.size()) {
    append(result, l[i]);
    i += 1;
  }
  while (j < r.size()) {
    append(result, r[j]);
    j += 1;
  }

  return result;
}

vector<pair<int, int>> solve(vector<Building> &buildings, int start, int end) {
  if (start == end) {
    vector<pair<int, int>> result = {
        {buildings[start].left, buildings[start].height},
        {buildings[start].right, 0}};

    return result;
  }

  int mid = (start + end) / 2;
  vector<pair<int, int>> l = solve(buildings, start, mid);
  vector<pair<int, int>> r = solve(buildings, mid + 1, end);

  return merge(l, r);
}

bool compare(Building &a, Building &b) {
  return make_tuple(a.left, a.height, a.right) <
         make_tuple(b.left, b.height, b.right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  vector<Building> buildings(N);
  for (int i = 0; i < N; i++) {
    cin >> buildings[i].left >> buildings[i].height >> buildings[i].right;
  }

  sort(buildings.begin(), buildings.end(), compare);

  vector<pair<int, int>> result = solve(buildings, 0, N - 1);
  for (const auto &p : result) {
    cout << p.first << ' ' << p.second << ' ';
  }
}