#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;

  for (int i = 0; i < N; i++) {
    s = "";

    for (int j = 0; j < N - i - 1; j++) {
      s += ' ';
    }

    for (int j = 0; j < i; j++) {
      s += '*';
    }

    s += '*';

    cout << s << endl;
  }

  for (int i = N - 2; i >= 0; i--) {
    s = "";

    for (int j = 0; j < N - i - 1; j++) {
      s += ' ';
    }

    for (int j = 0; j < i; j++) {
      s += '*';
    }

    s += '*';

    cout << s;

    if (i != 0) {
      cout << endl;
    }
  }

  return 0;
}