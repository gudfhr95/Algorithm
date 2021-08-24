#include <iostream>

using namespace std;

int main() {
  int A, B, C;

  cin >> A >> B >> C;

  cout << max(B - A - 1, C - B - 1);
}
