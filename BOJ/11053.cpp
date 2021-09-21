#include <cstring>
#include <iostream>

using namespace std;

int cache[1001];
int a[1001];

void lis(int n) {
  for (int i = 0; i < n; i++) {
    cache[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i] && cache[i] < cache[j] + 1) cache[i] = cache[j] + 1;
    }
  }
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  lis(N);

  int result = -987654321;
  for (int i = 0; i < N; i++) {
    result = max(result, cache[i]);
  }
  cout << result;
}