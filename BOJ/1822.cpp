#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  int na, nb, n;
  set<int> A, B;

  cin >> na >> nb;

  for (int i = 0; i < na; i++) {
    cin >> n;
    A.insert(n);
  }

  for (int i = 0; i < nb; i++) {
    cin >> n;
    B.insert(n);
  }

  set<int> result;
  set_difference(A.begin(), A.end(), B.begin(), B.end(),
                 inserter(result, result.begin()));

  cout << result.size() << '\n';

  for (const auto &elem : result) {
    cout << elem << ' ';
  }
}
