#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    s = "";

    for (int j = 0; j < i; j++) {
      s += '*';
    }

    cout << s << endl;
  }

  for (int i = N - 1; i >= 1; i--) {
    s = "";

    for (int j = 0; j < i; j++) {
      s += '*';
    }

    cout << s;
    if (i != 1) {
      cout << endl;
    }
  }

  return 0;
}