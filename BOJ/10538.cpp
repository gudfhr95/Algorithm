#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct AhoCorasick {
  struct Node {
    int children[2];
    int pi;
    int valid;
    Node() {
      for (int i = 0; i < 2; i++) {
        children[i] = -1;
      }
      valid = -1;
      pi = -1;
    }
  };

  vector<Node> trie;
  int root;

  int init() {
    Node x;
    trie.push_back(x);
    return (int)trie.size() - 1;
  }

  AhoCorasick() { root = init(); }

  int add(int node, string &s, int index) {
    if (index == s.size()) {
      trie[node].valid = node;
      return node;
    }

    int c = (s[index] == 'o' ? 1 : 0);
    if (trie[node].children[c] == -1) {
      int next = init();
      trie[node].children[c] = next;
    }

    return add(trie[node].children[c], s, index + 1);
  }

  int add(string &s) { return add(root, s, 0); }

  void make() {
    queue<int> q;

    trie[root].pi = root;
    q.push(root);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int i = 0; i < 2; i++) {
        int next = trie[cur].children[i];

        if (next == -1) continue;

        if (cur == root) {
          trie[next].pi = root;
        } else {
          int x = trie[cur].pi;

          while (x != root && trie[x].children[i] == -1) {
            x = trie[x].pi;
          }

          if (trie[x].children[i] != -1) {
            x = trie[x].children[i];
          }

          trie[next].pi = x;
        }

        q.push(next);
      }
    }
  }

  int next(int node, char ch) {
    int c = (ch == 'o' ? 1 : 0);

    while (node != root && trie[node].children[c] == -1) {
      node = trie[node].pi;
    }

    if (trie[node].children[c] != -1) {
      node = trie[node].children[c];
    }

    return node;
  }

  vector<int> search(string &s) {
    int n = s.length();

    vector<int> ans(n, -1);

    int node = root;
    for (int i = 0; i < n; i++) {
      node = next(node, s[i]);
      ans[i] = trie[node].valid;
    }

    return ans;
  }
};

vector<int> preprocessing(vector<int> &p) {
  int m = p.size();

  vector<int> pi(m);
  pi[0] = 0;

  int j = 0;
  for (int i = 1; i < m; i++) {
    while (j > 0 && p[i] != p[j]) {
      j = pi[j - 1];
    }

    if (p[i] == p[j]) {
      pi[i] = j + 1;
      j += 1;
    } else {
      pi[i] = 0;
    }
  }

  return pi;
}

int kmp(vector<int> &s, vector<int> &p, vector<int> &pi) {
  int ans = 0;

  int n = s.size();
  int m = p.size();

  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j > 0 && s[i] != p[j]) {
      j = pi[j - 1];
    }
    if (s[i] == p[j]) {
      if (j == m - 1) {
        ans += 1;
        j = pi[j];
      } else {
        j += 1;
      }
    }
  }

  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int rs, cs, rb, cb;

  cin >> rs >> cs >> rb >> cb;

  AhoCorasick aho;
  vector<string> small(rs);
  vector<string> big(rb);

  vector<int> p(rs);

  for (int i = 0; i < rs; i++) {
    cin >> small[i];
    p[i] = aho.add(small[i]);
  }

  for (int i = 0; i < rb; i++) {
    cin >> big[i];
  }

  aho.make();

  vector<vector<int>> d(rb);
  for (int i = 0; i < rb; i++) {
    d[i] = aho.search(big[i]);
  }

  auto pi = preprocessing(p);

  int ans = 0;
  for (int j = cs - 1; j < cb; j++) {
    vector<int> s(rb);

    for (int i = 0; i < rb; i++) {
      s[i] = d[i][j];
    }

    ans += kmp(s, p, pi);
  }

  cout << ans;

  return 0;
}
