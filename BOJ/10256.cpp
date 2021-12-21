#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int children[4];
  int pi;
  int cnt;

  Node() {
    for (int i = 0; i < 4; i++) {
      children[i] = -1;
    }
    pi = -1;
    cnt = 0;
  }
};

vector<Node> trie;
int root;

int convert(char x) {
  if (x == 'A')
    return 0;
  else if (x == 'T')
    return 1;
  else if (x == 'G')
    return 2;
  else
    return 3;
}

int init() {
  Node x;
  trie.push_back(x);
  return (int)trie.size() - 1;
}

void add(int node, string &s, int index) {
  if (index == s.length()) {
    trie[node].cnt = 1;
    return;
  }

  int c = convert(s[index]);
  if (trie[node].children[c] == -1) {
    int next = init();
    trie[node].children[c] = next;
  }

  int children = trie[node].children[c];
  add(children, s, index + 1);
}

char buffer[1111111];

int main() {
  int T;

  cin >> T;

  while (T--) {
    trie.clear();

    int n, m;

    cin >> n >> m;

    string s, p;

    cin >> s >> p;

    root = init();

    vector<string> a;
    for (int i = 0; i < m; i++) {
      for (int j = i; j < m; j++) {
        string p2 = p;
        reverse(p2.begin() + i, p2.begin() + j + 1);
        a.push_back(p2);
      }
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (string &s : a) {
      add(root, s, 0);
    }

    queue<int> q;

    trie[root].pi = root;
    q.push(root);

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int next = trie[current].children[i];

        if (next == -1) continue;

        if (current == root) {
          trie[next].pi = root;
        } else {
          int x = trie[current].pi;

          while (x != root && trie[x].children[i] == -1) {
            x = trie[x].pi;
          }

          if (trie[x].children[i] != -1) {
            x = trie[x].children[i];
          }

          trie[next].pi = x;
        }

        int pi = trie[next].pi;
        trie[next].cnt += trie[pi].cnt;
        q.push(next);
      }
    }

    int result = 0;
    int node = root;
    for (int i = 0; i < s.length(); i++) {
      int c = convert(s[i]);

      while (node != root && trie[node].children[c] == -1) {
        node = trie[node].pi;
      }

      if (trie[node].children[c] != -1) {
        node = trie[node].children[c];
      }

      result += trie[node].cnt;
    }

    cout << result << '\n';
  }
}