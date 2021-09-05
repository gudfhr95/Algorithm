#include <iostream>

using namespace std;

int main() {
  int A, B;

  cin >> A >> B;

  int Ay = (A % 4 == 0) ? (A / 4) : (A / 4) + 1;
  int By = (B % 4 == 0) ? (B / 4) : (B / 4) + 1;
  int Ax = (A % 4 == 0) ? 4 : (A % 4);
  int Bx = (B % 4 == 0) ? 4 : (B % 4);

  cout << abs(By - Ay) + abs(Bx - Ax);
}