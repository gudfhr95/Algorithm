#include <iostream>

using namespace std;

int main() {
  int T;
  float n;
  string s;

  cin >> T;
  cout << fixed;      // 소숫점 자리 고정
  cout.precision(2);  // 둘째자리까지 출력

  while (T--) {
    cin >> n;
    getline(cin, s);  // 한줄 받아오기

    for (int i = 0; i < s.length(); ++i) {
      switch (s[i]) {
        case '@':
          n *= 3;
          break;
        case '%':
          n += 5;
          break;
        case '#':
          n -= 7;
          break;
      }
    }

    cout << n << '\n';
  }
}