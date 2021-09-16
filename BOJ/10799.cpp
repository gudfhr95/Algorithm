#include <iostream>
#include <stack>

using namespace std;

int main() {
  string p;
  stack<int> s;

  cin >> p;

  int result = 0;
  for (int i = 0; i < p.length(); i++) {
    if (p[i] == '(') {
      s.push(i);
    } else if (p[i] == ')') {
      if (s.top() + 1 == i) {
        result += s.size() - 1;
      } else {
        result += 1;
      }
      s.pop();
    }
  }

  cout << result;
}