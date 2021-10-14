#include <iostream>

using namespace std;

struct Node {
  int left, right;
  int order, depth;
};

int N;
Node tree[10001];
int l[10001];
int r[10001];
int cnt[10001];
int order = 0;

void inorder(int node, int depth) {
  if (node == -1) return;

  inorder(tree[node].left, depth + 1);

  tree[node].order = ++order;
  tree[node].depth = depth;

  inorder(tree[node].right, depth + 1);
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x, y, z;

    cin >> x >> y >> z;

    tree[x].left = y;
    tree[x].right = z;

    if (y != -1) cnt[y] += 1;
    if (z != -1) cnt[z] += 1;
  }

  int root = 0;
  for (int i = 1; i <= N; i++) {
    if (cnt[i] == 0) {
      root = i;
    }
  }

  inorder(root, 1);

  int max_depth = 0;
  for (int i = 1; i <= N; i++) {
    int depth = tree[i].depth;
    int order = tree[i].order;

    if (l[depth] == 0) {
      l[depth] = order;
    } else {
      l[depth] = min(l[depth], order);
    }

    r[depth] = max(r[depth], order);
    max_depth = max(max_depth, depth);
  }

  int ans = 0;
  int ans_level = 0;
  for (int i = 1; i <= max_depth; i++) {
    if (ans < r[i] - l[i] + 1) {
      ans = r[i] - l[i] + 1;
      ans_level = i;
    }
  }

  cout << ans_level << ' ' << ans << '\n';
}