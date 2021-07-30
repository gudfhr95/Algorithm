#include <iostream>
#include <string>

using namespace std;

int main() {
  int A, B;
  string S;

  while (true) {
    cin >> A >> B;
    if (A == 0 && B == 0) {
      break;
    }
    S = (A > B) ? "Yes" : "No";
    cout << S << '\n';
  }

  return 0;
}