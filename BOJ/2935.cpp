#include <iostream>
#include <string>

using namespace std;

int main() {
  string A, B;
  char op;

  cin >> A >> op >> B;

  if (op == '+') {
    if (A.length() >= B.length()) {
      A[A.length() - B.length()] += 1;
      cout << A;
    } else {
      B[B.length() - A.length()] += 1;
      cout << B;
    }
  } else {
    cout << A;
    for (int i = 0; i < B.length() - 1; ++i) {
      cout << '0';
    }
  }
}