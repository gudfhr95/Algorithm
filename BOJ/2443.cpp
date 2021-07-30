#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;

  for (int i = N - 1; i >= 0; i--) {
    s = "";

    for (int j = 0; j < N - i - 1; j++) {
      s += ' ';
    }

    for (int j = 0; j < i; j++) {
      s += '*';
    }

    s += '*';

    for (int j = 0; j < i; j++) {
      s += '*';
    }

    cout << s << endl;
  }

  return 0;
}