#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct lecture {
  int p, d;
};

bool cmp(const lecture &a, const lecture &b) { return a.d > b.d; }

int main() {
  int n;

  cin >> n;

  vector<lecture> lectures(n);

  for (int i = 0; i < n; i++) {
    cin >> lectures[i].p >> lectures[i].d;
  }

  sort(lectures.begin(), lectures.end(), cmp);

  int index = 0;
  priority_queue<int> q;

  int result = 0;
  for (int i = 10000; i >= 1; i--) {
    while (index < n && lectures[index].d == i) {
      q.push(lectures[index].p);
      index += 1;
    }
    if (!q.empty()) {
      result += q.top();
      q.pop();
    }
  }
  cout << result;
}