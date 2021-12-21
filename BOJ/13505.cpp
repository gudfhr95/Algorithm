#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int children[2];

  Node() {
    for (int i = 0; i < 2; i++) {
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

  int children = trie[node].children[c];
  return add(children, s, index + 1);
}

int search(int node, string &s, int index, int sum) {
  if (index == s.length()) {
    return sum;
  }

  int c = s[index] - '0';
  if (trie[node].children[!c] != -1) {
    int children = trie[node].children[!c];
    return search(children, s, index + 1, sum + (int)pow(2, 31 - index));
  } else {
    int children = trie[node].children[c];
    return search(children, s, index + 1, sum);
  }
}

int main() {
  int N;

  cin >> N;

  root = init();

  vector<string> numbers;

  int n;
  for (int i = 0; i < N; i++) {
    cin >> n;

    bitset<32> b(n);

    string bitString = b.to_string();
    add(root, bitString, 0);
    numbers.push_back(bitString);
  }

  int result = 0;
  for (string s : numbers) {
    result = max(result, search(root, s, 0, 0));
  }

  cout << result;
}