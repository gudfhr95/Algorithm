#include <iostream>
#include <stack>

using namespace std;

int main() {
  string s;
  int M;
  char c, input;
  stack<char> left, right;

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s >> M;

  for (int i = 0; i < s.length(); i++) {
    left.push(s[i]);
  }

  while (M--) {
    cin >> c;

    if (c == 'L') {
      if (!left.empty()) {
        right.push(left.top());
        left.pop();
      }
    } else if (c == 'D') {
      if (!right.empty()) {
        left.push(right.top());
        right.pop();
      }
    } else if (c == 'B') {
      if (!left.empty()) {
        left.pop();
      }
    } else if (c == 'P') {
      cin >> input;
      left.push(input);
    }
  }

  while (!left.empty()) {
    right.push(left.top());
    left.pop();
  }
  while (!right.empty()) {
    cout << right.top();
    right.pop();
  }
}