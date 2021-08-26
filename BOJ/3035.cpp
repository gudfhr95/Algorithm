#include <iostream>

using namespace std;

char ORIGINAL[50][50] = {
    0,
};

char PAPER[250][250] = {
    0,
};

int main() {
  int R, C, ZR, ZC;
  string s;

  cin >> R >> C >> ZR >> ZC;

  for (int i = 0; i < R; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      ORIGINAL[i][j] = s[j];
    }
  }

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      for (int h = 0; h < ZR; h++) {
        for (int w = 0; w < ZC; w++) {
          PAPER[ZR * y + h][ZC * x + w] = ORIGINAL[y][x];
        }
      }
    }
  }

  for (int y = 0; y < R * ZR; y++) {
    for (int x = 0; x < C * ZC; x++) {
      if (PAPER[y][x] != 0) {
        cout << PAPER[y][x];
      }
    }
    cout << '\n';
  }
}