#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int N;
int map[20][20];
bool visited[20][20];
int weight = 2;
int eat = 0;
int result = 0;

bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b) {
  if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
  return get<1>(a) < get<1>(b);
}

pair<int, int> bfs(int x, int y) {
  queue<tuple<int, int, int>> q;

  q.push({x, y, 0});
  visited[y][x] = true;

  int xc, yc, tc, xn, yn, tn;
  vector<tuple<int, int, int>> candidates;
  while (!q.empty()) {
    tie(xc, yc, tc) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];
      tn = tc + 1;

      if (xn < 0 || yn < 0 || xn > N - 1 || yn > N - 1) continue;

      if (map[yn][xn] > weight || visited[yn][xn]) continue;

      if (candidates.size() != 0 && tn > get<2>(candidates[0])) continue;

      if (map[yn][xn] != 0 && map[yn][xn] < weight) {
        candidates.push_back({xn, yn, tn});
      }

      // cout << xn << ' ' << yn << '\n';
      q.push({xn, yn, tn});
      visited[yn][xn] = true;
    }
  }

  if (candidates.size() == 0) {
    return {-1, -1};
  }

  sort(candidates.begin(), candidates.end(), cmp);

  int xd, yd, td;
  tie(xd, yd, td) = candidates[0];
  map[yd][xd] = 0;
  result += td;

  eat += 1;
  if (weight == eat) {
    weight += 1;
    eat = 0;
  }

  return {xd, yd};
}

int main() {
  cin >> N;

  int xs, ys;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> map[y][x];

      if (map[y][x] == 9) {
        xs = x;
        ys = y;
        map[y][x] = 0;
      }
    }
  }

  pair<int, int> shark = {xs, ys};
  while (true) {
    memset(visited, false, sizeof(visited));
    shark = bfs(shark.first, shark.second);

    if (shark.first == -1 && shark.second == -1) break;
  }

  cout << result;
}