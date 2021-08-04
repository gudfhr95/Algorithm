#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n, result = 0;
  vector<int> a, b;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> n;
    a.push_back(n);
  }

  for (int i = 0; i < N; i++) {
    cin >> n;
    b.push_back(n);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<>());

  for (int i = 0; i < N; i++) {
    result += a[i] * b[i];
  }

  cout << result;
}