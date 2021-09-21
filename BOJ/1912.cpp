#include <iostream>

using namespace std;

int cache[100000];
int seq[100000];

void sum(int n) {
  cache[0] = seq[0];
  for (int i = 1; i < n; i++) {
    cache[i] = max(cache[i - 1] + seq[i], seq[i]);
  }
}

int main() {
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }

  sum(n);

  int result = -987654321;
  for (int i = 0; i < n; i++) {
    result = max(result, cache[i]);
  }
  cout << result;
}