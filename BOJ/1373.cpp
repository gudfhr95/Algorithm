#include <iostream>

using namespace std;

string convertBase(long long n, int b) {
  string result = "";

  while (n > 0) {
    int digit = n % b;

    if (digit < 10) {
      result = (char)(digit + '0') + result;
    } else {
      result = (char)(digit - 10 + 'A') + result;
    }

    n = n / b;
  }

  return result;
}

int main() {
  long long N;
  int B;

  cin >> N >> B;

  cout << convertBase(N, B);
}