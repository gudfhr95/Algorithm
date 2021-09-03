#include <iostream>

using namespace std;

int getDistance(string a, string b) {
  int result = 0;

  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) result++;
  }

  return result;
}

int main() {
  string A, B;

  cin >> A >> B;

  int result = 987654321;
  for (int i = 0; i <= B.length() - A.length(); i++) {
    result = min(result, getDistance(B.substr(i, A.length()), A));
  }

  cout << result;
}