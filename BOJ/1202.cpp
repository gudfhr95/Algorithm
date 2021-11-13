#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct jewel {
  int m, v, w;
};

bool compare(jewel a, jewel b) {
  return a.m < b.m || (a.m == b.m && a.w < b.w);
}

int main() {
  int N, K;

  scanf("%d %d", &N, &K);

  vector<jewel> jewels(N + K);

  for (int i = 0; i < N; i++) {
    scanf("%d %d", &jewels[i].m, &jewels[i].v);
  }

  for (int i = 0; i < K; i++) {
    scanf("%d", &jewels[i + N].m);
    jewels[i + N].w = 1;
  }

  sort(jewels.begin(), jewels.end(), compare);

  long long result = 0;
  priority_queue<int> q;

  for (auto &j : jewels) {
    if (j.w == 0) {
      q.push(j.v);
    } else {
      if (!q.empty()) {
        result += (long long)q.top();
        q.pop();
      }
    }
  }

  printf("%lld", result);
}