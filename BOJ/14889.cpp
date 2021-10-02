#include <iostream>
#include <vector>

using namespace std;

int stat[20][20];

int team(int index, int n, vector<int>& start, vector<int>& link) {
  if (index == n) {
    if (start.size() * 2 != n) return 987654321;
    if (link.size() * 2 != n) return 987654321;

    int t1 = 0;
    int t2 = 0;
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        if (i == j) continue;

        t1 += stat[start[i]][start[j]];
        t2 += stat[link[i]][link[j]];
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