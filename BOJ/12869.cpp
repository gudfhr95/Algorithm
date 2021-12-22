#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int d[61][61][61];

int attack(int a, int b, int c) {
  if (a < 0) return attack(0, b, c);
  if (b < 0) return attack(a, 0, c);
  if (c < 0) return attack(a, b, 0);

  if (a == 0 && b == 0 && c == 0) return 0;

  int &ret = d[a][b][c];

  if (ret != -1) return ret;

  ret = 987654321;
  vector<int> damage = {1, 3, 9};
  do {
    ret = min(ret, attack(a - damage[0], b - damage[1], c - damage[2]));
  } while (next_permutation(damage.begin(), damage.end()));

  ret += 1;

  return ret;
}

int main() {
  int N;

  cin >> N;

  int scv[3] = {0, 0, 0};
  for (int i = 0; i < N; i++) {
    cin >> scv[i];
  }

  memset(d, -1, sizeof(d));

  cout << attack(scv[0], scv[1], scv[2]);
}