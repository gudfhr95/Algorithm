#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

char LETTER[100][100];

void read(string s) {
  int n = sqrt(s.length());

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      LETTER[y][x] = s[y * n + x];
    }
  }

  for (int x = n - 1; x >= 0; x--) {
    for (int y = 0; y < n; y++) {
      cout << LETTER[y][x];
    }
  }

  cout << '\n';
}

int main() {
  int T;
  string s;

  cin >> T;

  while (T--) {
    cin >> s;

    memset(LETTER, 0, sizeof(LETTER));

    read(s);
  }
}