#include <iostream>
#include <vector>

using namespace std;

struct Trie {
  struct Node {
    int children[2];
    int cnt[2];
    bool valid;

    Node() {
      for (int i = 0; i < 2; i++) {
        children[i] = -1;
        cnt[i] = 0;
      }
      valid = 0;
    }
  };

  vector<Node> trie;
  int root;

  int init() {
    Node x;
    trie.push_back(x);
    return trie.size() - 1;
  }

  Trie() { root = init(); }

  void add(int node, int num, int bit) {
    if (bit == -1) {
      trie[node].valid = true;
      return;
    }

    int c = (num >> bit) & 1;
    if (trie[node].children[c] == -1) {
      int next = init();
      trie[node].children[c] = next;
    }

    trie[node].cnt[c] += 1;
    add(trie[node].children[c], num, bit - 1);
  }

  void add(int num) { add(root, num, 20); }

  int query(int node, int num, int k, int bit) {
    if (bit == -1) return 0;

    int c1 = (k >> bit) & 1;
    int c2 = (num >> bit) & 1;

    int result = 0;
    if (c1 == 1) {
      result += trie[node].cnt[c2];
      c2 = 1 - c2;
    }

    if (trie[node].children[c2] == -1) return result;

    result += query(trie[node].children[c2], num, k, bit - 1);
    return result;
  }

  int query(int num, int k) { return query(root, num, k, 20); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;

  cin >> N >> K;

  long long result = 0;

  Trie trie;
  trie.add(0);

  int prefix = 0;
  for (int i = 0; i < N; i++) {
    int num;

    cin >> num;

    prefix ^= num;

    result += trie.query(prefix, K);
    trie.add(prefix);
  }

  cout << result;
}