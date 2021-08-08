#include <algorithm>
#include <iostream>

using namespace std;

string toBinary(long long n) {
  string result = "";

  while (n > 0) {
    result += (n % 2) + '0';
    n = n / 2;
  }

  reverse(result.begin(), result.end());

  return result;
}

int main() {
  long long n;

  cin >> n;

  cout << toBinary(n);
}