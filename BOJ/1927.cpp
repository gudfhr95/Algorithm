#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N, x;
  priority_queue<int, vector<int>, greater<int>> pq;

  // cin, cout 빠르게하기
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  while (N--) {
    cin >> x;

    if (x == 0) {
      if (pq.empty())
        cout << 0 << '\n';
      else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(x);
    }
  }
}
