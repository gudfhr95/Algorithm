#include <iostream>

using namespace std;

bool isPrime(int n) {
  if (n <= 3) return true;

  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

int main() {
  string s;
  int n = 0;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (isupper(s[i]))
      n += s[i] - 'A' + 27;
    else
      n += s[i] - 'a' + 1;
  }

  if (isPrime(n))
    cout << "It is a prime word.";
  else
    cout << "It is not a prime word.";
}
