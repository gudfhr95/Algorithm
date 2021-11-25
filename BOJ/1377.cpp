#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;

  cin >> N;

  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }

  sort(A.begin(), A.end());

  int result = 0;
  for (int i = 0; i < N; i++) {
    result = max(result, A[i].second - i);
  }

  cout << result + 1;
}