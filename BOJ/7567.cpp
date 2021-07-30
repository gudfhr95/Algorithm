#include <iostream>

using namespace std;

int main() {
  string S;
  int result = 10;

  cin >> S;

  for (int i = 1; i < S.length(); ++i) {
    if (S[i] == S[i - 1]) {
      result += 5;
    } else {
      result += 10;
    }
  }

  cout << result;

  return 0;
}