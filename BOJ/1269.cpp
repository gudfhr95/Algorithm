#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  int a, b, n;
  set<int> A, B;

  cin >> a >> b;

  for (int i = 0; i < a; i++) {
    cin >> n;
    A.insert(n);
  }

  for (int i = 0; i < b; i++) {
    cin >> n;
    B.insert(n);
  }

  set<int> A_B;
  set_difference(A.begin(), A.end(), B.begin(), B.end(),
                 inserter(A_B, A_B.begin()));

  set<int> B_A;
  set_difference(B.begin(), B.end(), A.begin(), A.end(),
                 inserter(B_A, B_A.begin()));

  cout << A_B.size() + B_A.size();
}