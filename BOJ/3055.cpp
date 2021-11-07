#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int R, C;
char map[50][50];
bool visited[50][50];

void bfs(tuple<char, int, int, int> start) {
  queue<tuple<char, int, int, int>> q;

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (map[y][x] == '*') {
        q.push({'*', x, y, 0});
      }
    }
  }

  q.push(start);

  char c;
  int xc, yc, tc, xn, yn, tn;
  while (!q.empty()) {
    tie(c, xc, yc, tc) = q.front();
    q.pop();

    if (c == 'S') {
      if (map[yc][xc] == 'D') {
        cout << tc;
        return;
      }
    }

    for (int k = 0; k < 4; k++) {
      int xn = xc + dx[k];
      int yn = yc + dy[k];
      int tn = tc + 1;

      if (xn < 0 || yn < 0 || xn > C - 1 || yn > R - 1) continue;

      if (c == '*') {
        if (map[yn][xn] != '.') continue;

        q.push({'*', xn, yn, tn});
        map[yn][xn] = '*';
      } else if (c == 'S') {
        if (map[yn][xn] == 'X' || map[yn][xn] == '*') continue;

        if (visited[yn][xn]) continue;

        q.push({'S', xn, yn, tn});
        visited[yn][xn] = true;
      }
    }
    // break;
  }

  cout << "KAKTUS";
  return;
}

int main() {
  cin >> R >> C;

  string s;
  tuple<char, int, int, int> startPos;
  for (int y = 0; y < R; y++) {
    cin >> s;
    for (int x = 0; x < C; x++) {
      if (s[x] == 'S') {
        startPos = {'S', x, y, 0};
        visited[y][x] = true;
        map[y][x] = '.';
      } else {
        map[y][x] = s[x];
      }
    }
  }

  bfs(startPos);
}