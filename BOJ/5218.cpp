#include <iostream>

using namespace std;

int main() {
  int T;
  string A, B;

  cin >> T;

  while (T--) {
    cin >> A >> B;

    cout << "Distances: ";

    for (int i = 0; i < A.length(); i++) {
      if (A[i] <= B[i])
        cout << B[i] - A[i] << ' ';
      else
        cout << B[i] - A[i] + 26 << ' ';
    }

    cout << '\n';
  }
}