#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n, e, count = 0;
  stack<int> s;

  cin >> n;

  vector<char> result;
  while (n--) {
    cin >> e;
    if (e >= count) {
      for (int i = 1; i <= e - count; i++) {
        s.push(count + i);
        result.push_back('+');
      }
      count = e;
      if (s.top() != e) {
        cout << s.top() << '\n';
        cout << "NO";
        return 0;
      } else {
        s.pop();
        result.push_back('-');
      }
    } else {
      while (!s.empty() && s.top() != e) {
        s.pop();
        result.push_back('-');
      }

      if (s.empty()) {
        cout << "NO";
        return 0;
      } else {
        s.pop();
        result.push_back('-');
      }
    }
  }

  for (const auto &elem : result) {
    cout << elem << '\n';
  }
}