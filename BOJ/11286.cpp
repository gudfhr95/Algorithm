#include <iostream>
#include <queue>

using namespace std;

void pop(priority_queue<int, vector<int>, greater<int>> &plus,
         priority_queue<int> &minus) {
  if (minus.empty() && plus.empty()) {
    cout << 0 << '\n';
  } else if (minus.empty()) {
    cout << plus.top() << '\n';
    plus.pop();
  } else if (plus.empty()) {
    cout << minus.top() << '\n';
    minus.pop();
  } else if (abs(minus.top()) <= abs(plus.top())) {
    cout << minus.top() << '\n';
    minus.pop();
  } else {
    cout << plus.top() << '\n';
    plus.pop();
  }
}

int main() {
  int N, x;
  priority_queue<int> minus;
  priority_queue<int, vector<int>, greater<int>> plus;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  while (N--) {
    cin >> x;

    if (x == 0) {
      pop(plus, minus);
    } else if (x > 0) {
      plus.push(x);
    } else {
      minus.push(x);
    }
  }
}
