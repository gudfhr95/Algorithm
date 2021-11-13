#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;

  cin >> N;

  vector<int> A;
  for (int i = 0; i < N; i++) {
    int a;

    cin >> a;

    auto it = lower_bound(A.begin(), A.end(), a);

    if (it == A.end()) {
      A.push_back(a);
    } else {
      *it = a;
    }
  }

  cout << A.size();
}