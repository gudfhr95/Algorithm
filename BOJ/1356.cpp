#include <iostream>

using namespace std;

bool isEujin(string N) {
  for (int i = 1; i <= N.length() - 1; i++) {
    string a = N.substr(0, i);
    string b = N.substr(i, N.length() - i);

    int a_mult = 1;
    int b_mult = 1;

    for (int j = 0; j < a.length(); j++) {
      a_mult *= a[j] - '0';
    }

    for (int j = 0; j < b.length(); j++) {
      b_mult *= b[j] - '0';
    }

    if (a_mult == b_mult) {
      return true;
    }
  }

  return false;
}

int main() {
  string N;

  cin >> N;

  if (isEujin(N))
    cout << "YES";
  else
    cout << "NO";
}