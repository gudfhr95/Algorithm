#include <iostream>
#include <vector>

using namespace std;

int stat[20][20];

int team(int index, int n, vector<int>& start, vector<int>& link) {
  if (index == n) {
    if (start.size() < 1) return 987654321;
    if (link.size() < 1) return 987654321;

    int t1 = 0;
    for (int y = 0; y < start.size(); y++) {
      for (int x = 0; x < start.size(); x++) {
        if (x == y) continue;

        t1 += stat[start[x]][start[y]];
      }
    }

    int t2 = 0;
    for (int y = 0; y < link.size(); y++) {
      for (int x = 0; x < link.size(); x++) {
        if (x == y) continue;

        t2 += stat[link[x]][link[y]];
      }
    }

    return abs(t1 - t2);
  }

  int result = 987654321;
  start.push_back(index);
  result = min(result, team(index + 1, n, start, link));
  start.pop_back();

  link.push_back(index);
  result = min(result, team(index + 1, n, start, link));
  link.pop_back();

  return result;
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> stat[i][j];
    }
  }

  vector<int> start, link;
  cout << team(0, N, start, link);
}