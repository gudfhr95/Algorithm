#include <iostream>
#include <stack>

using namespace std;

int numbers[26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  stack<char> op;

  cin >> s;

  for (char c : s) {
    if (isalpha(c)) {
      cout << c;
    } else if (c == '(') {
      op.push(c);
    } else if (c == ')') {
      while (op.top() != '(') {
        cout << op.top();
        op.pop();
      }
      op.pop();
    } else if (c == '*' || c == '/') {
      while (!op.empty() && op.top() != '(' && op.top() != '+' &&
             op.top() != '-') {
        cout << op.top();
        op.pop();
      }
      op.push(c);
    } else if (c == '+' || c == '-') {
      while (!op.empty() && op.top() != '(') {
        cout << op.top();
        op.pop();
      }
      op.push(c);
    }
  }

  while (!op.empty()) {
    cout << op.top();
    op.pop();
  }
}