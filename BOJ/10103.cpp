#include <iostream>

using namespace std;

int main() {
  int n;
  int c, s;
  int c_score = 100;
  int s_score = 100;

  cin >> n;

  while (n--) {
    cin >> c >> s;
    if (c > s) {
      s_score -= c;
    } else if (c < s) {
      c_score -= s;
    }
  }
  cout << c_score << '\n' << s_score;
}