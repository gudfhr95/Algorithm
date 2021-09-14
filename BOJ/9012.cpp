#include <iostream>
#include <stack>

using namespace std;

bool VPS(string s) {
  stack<char> p;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      p.push(s[i]);
    } else {
      if (p.empty()) return false;

      if (p.top() == '(') {
        p.pop();
        continue;
      }
    }
  }

  if (p.size() == 0)
    return true;
  else
    return false;
}

int main() {
  int T;
  string s;

  cin >> T;

  while (T--) {
    cin >> s;

    if (VPS(s))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}