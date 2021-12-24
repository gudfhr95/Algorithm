#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int d[1000][1000];

int largest(vector<int> &a) {
  int n = a.size();

  stack<int> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    while (!s.empty() && a[s.top()] > a[i]) {
      int height = a[s.top()];
      s.pop();

      int width = i;
      if (!s.empty()) {
        width = (i - s.top() - 1);
      }

      if (ans < width * height) {
        ans = width * height;
      }
    }

    s.push(i);
  }

  while (!s.empty()) {
    int height = a[s.top()];
    s.pop();

    int width = n;
    if (!s.empty()) {
      width = n - s.top() - 1;
    }

    if (ans < width * height) {
      ans = width * height;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;

  while (true) {
    cin >> n >> m;

    if (n == 0 && m == 0) break;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> d[i][j];
      }
    }

    int ans = 0;
    vector<int> a(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (d[i][j] == 0) {
          a[j] = 0;
        } else {
          a[j] += 1;
        }
      }

      int cur = largest(a);
      if (ans < cur) ans = cur;
    }

    cout << ans << '\n';
  }

  return 0;
}
