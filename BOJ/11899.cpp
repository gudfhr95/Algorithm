#include <iostream>
#include <stack>

using namespace std;

int main() {
  string s;
  stack<char> parenthesis;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ')' && !parenthesis.empty() && parenthesis.top() == '(') {
      parenthesis.pop();
    } else {
      parenthesis.push(s[i]);
    }
  }

  cout << parenthesis.size();
} 