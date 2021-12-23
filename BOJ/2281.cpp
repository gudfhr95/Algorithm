#include <cstring>
#include <iostream>

using namespace std;

int N, M;
int names[1000];
int d[1000][1000];

int write(int index, int cnt) {
  if (index == N) return 0;

  int& ret = d[index][cnt];

  if (ret != -1) return ret;

  int space = (M - (cnt - 1));
  int cost = space * space;
  ret = write(index + 1, names[index] + 1) + cost;
  if (cnt + names[index] <= M) {
    int cur = write(index + 1, cnt + names[index] + 1);
    ret = min(ret, cur);
  }

  return ret;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> names[i];
  }

  memset(d, -1, sizeof(d));

  cout << write(1, names[0] + 1);
}
