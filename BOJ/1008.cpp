#include <iostream>

using namespace std;

int main() {
  double A, B;
  cin >> A >> B;
  cout.precision(15);  // 소숫점 15째자리까지 출력
  cout << A / B;
}