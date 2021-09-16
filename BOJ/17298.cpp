#include <iostream>
#include <stack>

using namespace std;

int main() {
  int N, a;
  int result[1000000];
  stack<pair<int, int>> s;

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a;

    while (!s.empty() && (s.top().first < a)) {
      result[s.top().second] = a;
      s.pop();
    }

    s.push({a, i});
  }

  while (!s.empty()) {
    result[s.top().second] = -1;
    s.pop();
  }

  for (int i = 0; i < N; i++) {
    cout << result[i] << ' ';
  }
}