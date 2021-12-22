#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct AhoCorasick {
  struct Node {
    map<int, int> children;
    int pi;
    int len;

    Node() {
      pi = -1;
      len = 0;
    }
  };

  vector<Node> trie;
  int root;

  int init() {
    Node x;
    trie.push_back(x);
    return trie.size() - 1;
  }

  AhoCorasick() { root = init(); }

  void add(int node, string &s, int index, int stringIndex) {
    if (index == s.length()) {
      trie[node].len = index;
      return;
    }

    int c = s[index] - 'a';
    if (trie[node].children.count(c) == 0) {
      int next = init();
      trie[node].children[c] = next;
    }

    add(trie[node].children[c], s, index + 1, stringIndex);
  }

  void add(string &s, int index) { add(root, s, 0, index); }

  void make() {
    queue<int> q;

    trie[root].pi = root;
    q.push(root);

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int i = 0; i < 26; i++) {
        if (trie[current].children.count(i) == 0) continue;

        int next = trie[current].children[i];
        if (current == root) {
          trie[next].pi = root;
        } else {
          int x = trie[current].pi;
          while (x != root & trie[x].children.count(i) == 0) {
            x = trie[x].pi;
          }

          if (trie[x].children.count(i) > 0) {
            x = trie[x].children[i];
          }
          trie[next].pi = x;
        }

        int pi = trie[next].pi;
        trie[next].len = max(trie[next].len, trie[pi].len);
        q.push(next);
      }
    }
  }

  int next(int node, char ch) {
    int c = ch - 'a';
    while (node != root && trie[node].children.count(c) == 0) {
      node = trie[node].pi;
    }

    if (trie[node].children.count(c) > 0) {
      node = trie[node].children[c];
    }

    return node;
  }

  int solve(string &s) {
    int node = root;

    vector<pair<int, int>> matches;
    for (int i = 0; i < s.length(); i++) {
      node = next(node, s[i]);
      if (trie[node].len > 0) {
        matches.push_back({i - trie[node].len + 1, -1});
        matches.push_back({i, 1});
      }
    }

    int result = 0;

    sort(matches.begin(), matches.end());

    int start = 0;
    int open = 0;
    for (auto &p : matches) {
      if (p.second == -1) {
        if (open == 0) {
          start = p.first;
        }
        open += 1;
      } else {
        open -= 1;
        if (open == 0) {
          result += p.first - start + 1;
        }
      }
    }

    return result;
  }
};

int main() {
  int N;

  cin >> N;

  string s;

  cin >> s;

  int M;

  cin >> M;

  AhoCorasick ac;
  for (int i = 0; i < M; i++) {
    string temp;

    cin >> temp;

    ac.add(temp, i + 1);
  }

  ac.make();

  cout << N - ac.solve(s) << '\n';
}