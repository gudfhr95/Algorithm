#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  int result = 0;

  while (cin >> S) {
    result += 1;
  }

  cout << result << '\n';

  return 0;
}