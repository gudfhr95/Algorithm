#include <iostream>

using namespace std;

int main() {
  int A, B, C, D, P, X, Y;

  cin >> A >> B >> C >> D >> P;

  X = P * A;
  Y = B + (max(P - C, 0) * D);

  cout << min(X, Y);
}