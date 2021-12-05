#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int board[5][5];
bool check[1000000];

void move(int x, int y, vector<int> digits) {
  if (digits.size() == 6) {
    int sum = 0;
    for (int i = 0; i < digits.size(); i++) {
      sum += digits[i] * pow(10, 5 - i);
    }

    check[sum] = true;
    return;
  }

  for (int k = 0; k < 4; k++) {
    int xn = x + dx[k];
    int yn = y + dy[k];

    if (xn < 0 || yn < 0 || xn > 4 || yn > 4) continue;

    vector<int> d(digits);
    d.push_back(board[yn][xn]);
    move(xn, yn, d);
  }
}

int main() {
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      cin >> board[y][x];
    }
  }

  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      vector<int> digits;
      digits.push_back(board[y][x]);

      move(x, y, digits);
    }
  }

  int result = 0;
  for (int i = 0; i < 1000000; i++) {
    result += check[i];
  }

  cout << result;
}