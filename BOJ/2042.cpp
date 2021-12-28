#include <iostream>

using namespace std;

long long a[1000000];
long long tree[3000000];

long long init(int node, int start, int end) {
  if (start == end) {
    return tree[node] = a[start];
  } else {
    return tree[node] = init(node * 2, start, (start + end) / 2) +
                        init(node * 2 + 1, (start + end) / 2 + 1, end);
  }
}

void update(int node, int start, int end, int i, long long diff) {
  if (i < start || i > end) return;

  tree[node] = tree[node] + diff;

  if (start != end) {
    update(node * 2, start, (start + end) / 2, i, diff);
    update(node * 2 + 1, (start + end) / 2 + 1, end, i, diff);
  }
}

long long sum(int node, int start, int end, int i, int j) {
  if (i > end || j < start) {
    return 0;
  }

  if (i <= start && end <= j) {
    return tree[node];
  }

  return sum(node * 2, start, (start + end) / 2, i, j) +
         sum(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
  int N, M, K;

  cin >> N >> M >> K;

  M += K;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  init(1, 0, N - 1);

  while (M--) {
    int t1;

    cin >> t1;

    if (t1 == 1) {
      int t2;
      long long t3;

      cin >> t2 >> t3;

      t2 -= 1;

      long long diff = t3 - a[t2];
      a[t2] = t3;
      update(1, 0, N - 1, t2, diff);
    } else if (t1 == 2) {
      int t2, t3;

      cin >> t2 >> t3;

      cout << sum(1, 0, N - 1, t2 - 1, t3 - 1) << '\n';
    }
  }
}