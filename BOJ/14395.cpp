#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>

using namespace std;

unordered_map<long, pair<long, char>> result;

long s, t;

void bfs(long start) {
  queue<long> q;

  q.push(start);
  result[start] = {start, '0'};

  long cur, next;
  while (!q.empty()) {
    cur = q.front();
    q.pop();

    if (cur == t) {
      return;
    }

    next = cur * cur;
    if (result.find(next) == result.end()) {
      q.push(next);
      result[next] = {cur, '*'};
    }

    next = cur + cur;
    if (result.find(next) == result.end()) {
      q.push(next);
      result[next] = {cur, '+'};
    }

    next = cur - cur;
    if (result.find(next) == result.end()) {
      q.push(next);
      result[next] = {cur, '-'};
    }

    if (cur != 0) {
      next = cur / cur;
      if (result.find(next) == result.end()) {
        q.push(next);
        result[next] = {cur, '/'};
      }
    }
  }
}

int main() {
  cin >> s >> t;

  bfs(s);

  if (result.find(t) == result.end()) {
    cout << -1;
    return 0;
  }

  stack<char> st;
  long from = t;
  char op;

  while (true) {
    tie(from, op) = result[from];

    st.push(op);

    if (from == s) break;
  }

  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }
}