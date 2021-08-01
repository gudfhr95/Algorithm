#include <iostream>

using namespace std;

int main() {
  int N;
  string s;

  cin >> N;
  cin.ignore();  // 개행문자 무시

  while (N--) {
    getline(cin, s);
    s = (char)toupper(s[0]) + s.substr(1, s.length());
    cout << s << '\n';
  }
}