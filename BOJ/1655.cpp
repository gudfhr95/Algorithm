#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<>> min_heap;

  int n;
  for (int i = 1; i <= N; i++) {
    cin >> n;

    if (max_heap.empty()) {
      max_heap.push(n);
    } else {
      if (n > max_heap.top()) {
        min_heap.push(n);
      } else {
        max_heap.push(n);
      }
    }

    while (min_heap.size() != (i / 2)) {
      if (min_heap.size() >= max_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
      } else {
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
    }

    cout << max_heap.top() << '\n';
  }
}