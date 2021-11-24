#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;

  cin >> N;

  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  for (const auto &elem : A) {
    cout << elem << '\n';
  }
}