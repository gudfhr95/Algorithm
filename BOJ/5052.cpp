#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int children[10];

  Node() {
    for (int i = 0; i < 10; i++) {
      children[i] = -1;
    }
  }
};

vector<Node> trie;
int root;

int init() {
  Node x;
  trie.push_back(x);
  return trie.size() - 1;
}

void add(int node, string &s, int index) {
  if (index == s.length()) return;

  int c = s[index] - '0';
  if (trie[node].children[c] == -1) {
    int next = init();
    trie[node].children[c] = next;
  }

  add(trie[node].children[c], s, index + 1);
}

bool search(int node, string &s, int index) {
  if (node == -1) return false;

  if (index == s.length()) return true;

  int c = s[index] - '0';
  return search(trie[node].children[c], s, index + 1);
}

int main() {
  int t, n;

  cin >> t;

  while (t--) {
    trie.clear();
    root = init();

    cin >> n;

    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
      cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end(), greater<>());

    bool ok = true;
    for (string number : numbers) {
      if (search(root, number, 0)) {
        ok = false;
        break;
      } else {
        add(root, number, 0);
      }
    }

    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}