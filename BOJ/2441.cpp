#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  string s;
  for (int i = N; i > 0; i--) {
    s = "";
    for (int j = 0; j < N - i; j++) {
      s += ' ';
    }
    for (int j = 0; j < i; j++) {
      s += '*';
    }
    cout << s << endl;
  }

  return 0;
}