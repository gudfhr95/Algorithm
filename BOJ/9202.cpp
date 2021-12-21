#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int scores[8] = {0, 0, 1, 1, 2, 3, 5, 11};

struct Node {
  int children[26];
  bool valid;

  Node() {
    for (int i = 0; i < 26; i++) {
      children[i] = -1;
    }
    valid = false;
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
  if (index == s.length()) {
    trie[node].valid = true;
    return;
  }

  int c = s[index] - 'A';
  if (trie[node].children[c] == -1) {
    int next = init();
    trie[node].children[c] = next;
  }

  add(trie[node].children[c], s, index + 1);
}

bool visited[4][4];

void search(int node, int x, int y, string s, vector<string> boggle,
            vector<string> &words) {
  if (x < 0 || y < 0 || x > 3 || y > 3) return;

  if (visited[y][x]) return;

  if (s.length() == 8) return;

  visited[y][x] = true;

  int c = boggle[y][x] - 'A';
  int next = trie[node].children[c];
  if (next == -1) {
    visited[y][x] = false;
    return;
  }

  s += boggle[y][x];
  if (trie[next].valid) {
    words.push_back(s);
  }

  for (int k = 0; k < 8; k++) {
    int xn = x + dx[k];
    int yn = y + dy[k];

    search(next, xn, yn, s, boggle, words);
  }

  visited[y][x] = false;
}

int main() {
  int w, b;

  cin >> w;

  root = init();

  string s;
  for (int i = 0; i < w; i++) {
    cin >> s;

    add(root, s, 0);
  }

  cin >> b;

  while (b--) {
    vector<string> boggle;

    string br;
    for (int i = 0; i < 4; i++) {
      cin >> br;

      boggle.push_back(br);
    }

    vector<string> words;
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        search(root, x, y, "", boggle, words);
      }
    }

    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());

    int score = 0;
    string longest = "";
    int cnt = 0;
    for (string &word : words) {
      score += scores[word.length() - 1];
      cnt++;

      if (word.length() > longest.length()) {
        longest = word;
      } else if ((word.length() == longest.length()) && (word < longest)) {
        longest = word;
      }
    }

    cout << score << ' ' << longest << ' ' << cnt << '\n';
  }
}