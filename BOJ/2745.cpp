#include <cmath>
#include <iostream>

using namespace std;

long long convertBase(string s, int b) {
  long long result = 0;

  for (int i = 0; i < s.length(); i++) {
    int n;
    if (isalpha(s[i]))
      n = s[i] - 'A' + 10;
    else
      n = s[i] - '0';
    result += (long long)(n * pow(b, s.length() - i - 1));
  }

  return result;
}

int main() {
  string S;
  int B;

  cin >> S >> B;

  cout << convertBase(S, B);
}