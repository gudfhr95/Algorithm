#include <iostream>

using namespace std;

int main() {
  int T;
  string s, p;

  cin >> T;

  while (T--) {
    cin >> s >> p;

    int result = s.length();
    size_t prev = 0, cur;
    string substring;

    cur = s.find(p);
    while (cur != string::npos) {
      result -= p.length() - 1;

      prev = cur + p.length() - 1;
      cur = s.find(p, prev);
    }

    cout << result << '\n';
  }
}