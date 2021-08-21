#include <iostream>

using namespace std;

int main() {
  int E, S, M, e, s, m;

  cin >> E >> S >> M;

  e = s = m = 1;
  int year = 1;
  while (true) {
    if (E == e && S == s && M == m) {
      cout << year;
      break;
    }

    e = (e + 1) == 15 ? 15 : (e + 1) % 15;
    s = (s + 1) == 28 ? 28 : (s + 1) % 28;
    m = (m + 1) == 19 ? 19 : (m + 1) % 19;

    year++;
  }
}
