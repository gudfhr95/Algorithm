#include <iostream>

using namespace std;

struct Node {
  int left;
  int right;
};

int N;
Node tree[50];

void preorder(int root) {
  if (root == -1) return;

  cout << (char)(root + 'A');
  preorder(tree[root].left);
  preorder(tree[root].right);
}

void inorder(int root) {
  if (root == -1) return;

  inorder(tree[root].left);
  cout << (char)(root + 'A');
  inorder(tree[root].right);
}

void postorder(int root) {
  if (root == -1) return;

  postorder(tree[root].left);
  postorder(tree[root].right);
  cout << (char)(root + 'A');
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    char root, left, right;

    cin >> root >> left >> right;

    root = root - 'A';

    if (left == '.') {
      tree[root].left = -1;
    } else {
      tree[root].left = left - 'A';
    }

    if (right == '.') {
      tree[root].right = -1;
    } else {
      tree[root].right = right - 'A';
    }
  }

  preorder(0);
  cout << '\n';

  inorder(0);
  cout << '\n';

  postorder(0);
  cout << '\n';
}