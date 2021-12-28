#include <cstdio>
int n;

int a[10000];
int b[10000];
int d[10000][10];

int go(int index, int turn) {
  if (index == n) return 0;

  if (d[index][turn] != -1) {
    return d[index][turn];
  }

  int cur = (a[index] + turn) % 10;

  int cost_left = (b[index] - cur + 10) % 10;
  int left = cost_left + go(index + 1, (turn + cost_left) % 10);

  int cost_right = (cur - b[index] + 10) % 10;
  int right = cost_right + go(index + 1, turn);

  if (left < right) {
    d[index][turn] = left;
  } else {
    d[index][turn] = right;
  }

  return d[index][turn];
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%1d", &a[i]);
  }

  for (int i = 0; i < n; i++) {
    scanf("%1d", &b[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      d[i][j] = -1;
    }
  }

  printf("%d\n", go(0, 0));

  return 0;
}
