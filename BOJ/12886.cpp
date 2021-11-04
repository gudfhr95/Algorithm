#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

bool visited[501][501][1001];

using namespace std;

int bfs(int A, int B, int C) {
  queue<vector<int>> q;

  q.push({A, B, C});
  visited[A][B][C] = true;

  while (!q.empty()) {
    vector<int> current = q.front();
    q.pop();

    if (current[0] == current[1] && current[1] == current[2]) {
      return 1;
    }

    int na, nb, nc;
    vector<int> temp;

    sort(current.begin(), current.end());

    na = current[0] + current[0];
    nb = current[1] - current[0];
    nc = current[2];
    temp = {na, nb, nc};
    sort(temp.begin(), temp.end());
    if (!visited[temp[0]][temp[1]][temp[2]]) {
      q.push(temp);
      visited[temp[0]][temp[1]][temp[2]] = true;
    }

    nb = current[1];
    nc = current[2] - current[0];
    temp = {na, nb, nc};
    sort(temp.begin(), temp.end());
    if (!visited[temp[0]][temp[1]][temp[2]]) {
      q.push(temp);
      visited[temp[0]][temp[1]][temp[2]] = true;
    }

    na = current[0];
    nb = current[1] + current[1];
    nc = current[2] - current[1];
    temp = {na, nb, nc};
    sort(temp.begin(), temp.end());
    if (!visited[temp[0]][temp[1]][temp[2]]) {
      q.push(temp);
      visited[temp[0]][temp[1]][temp[2]] = true;
    }
  }

  return 0;
}

int main() {
  int A, B, C;

  cin >> A >> B >> C;

  cout << bfs(A, B, C);
}