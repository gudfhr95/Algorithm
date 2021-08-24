#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N, K;
  queue<int> q;

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  cout << '<';

  while (q.size() > 1) {
    for (int i = 0; i < K - 1; i++) {
      q.push(q.front());
      q.pop();
    }

    cout << q.front() << ", ";
    q.pop();
  }

  cout << q.front() << '>';
}
