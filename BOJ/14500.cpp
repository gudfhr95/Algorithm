#include <iostream>
#include <vector>

using namespace std;

int paper[500][500];

int tetromino[19][4][2] = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}}, {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {0, 1}, {1, 1}, {2, 1}}, {{1, 0}, {1, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, {{0, 0}, {1, 0}, {0, 1}, {0, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}}, {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {2, 0}, {0, 1}, {1, 1}}, {{1, 0}, {0, 1}, {1, 1}, {0, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{1, 0}, {0, 1}, {1, 1}, {1, 2}}, {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {0, 2}}};

int sum(int n, int m) {
  int result = -987654321;

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      for (int i = 0; i < 19; i++) {
        vector<pair<int, int>> points;
        for (int j = 0; j < 4; j++) {
          points.push_back({x + tetromino[i][j][0], y + tetromino[i][j][1]});
        }

        bool isInside = true;
        for (const auto &point : points) {
          if (point.first < 0 || point.first >= m || point.second < 0 ||
              point.second >= n)
            isInside = false;
        }

        if (!isInside) continue;

        int temp = 0;
        for (const auto &point : points) {
          temp += paper[point.second][point.first];
        }
        result = max(result, temp);
      }
    }
  }

  return result;
}

int main() {
  int N, M;

  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> paper[y][x];
    }
  }

  cout << sum(N, M);
}