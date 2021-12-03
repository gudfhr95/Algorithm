#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string A;
  int B;

  cin >> A >> B;

  sort(A.begin(), A.end());

  int result = -1;
  do {
    int a = stoi(A);
    if (a < B && A[0] != '0') {
      result = max(result, a);
    }
  } while (next_permutation(A.begin(), A.end()));

  cout << result;
}