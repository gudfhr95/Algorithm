#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int cache[1001];
int a[1001];
int v[1001];

void lis(int n) {
  for (int i = 0; i < n; i++) {
    cache[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i] && cache[i] < cache[j] + 1) {
        cache[i] = cache[j] + 1;
        v[i] = j;
      }
    }
  }
}

int main() {
  int N;

  memset(v, -1, sizeof(v));

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  lis(N);

  int m = -987654321;
  int index = 0;
  for (int i = 0; i < N; i++) {
    if (m < cache[i]) {
      m = cache[i];
      index = i;
    }
  }

  vector<int> result;
  while (index != -1) {
    result.push_back(index);
    index = v[index];
  }
  reverse(result.begin(), result.end());

  cout << result.size() << '\n';
  for (const auto &elem : result) {
    cout << a[elem] << ' ';
  }
}