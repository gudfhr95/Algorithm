#include <iostream>

using namespace std;

int N;
int sign[10][10];
int result[10];

bool check(int index) {
  int sum = 0;
  for (int i = index; i >= 0; i--) {
    sum += result[i];
    if (sign[i][index] == 0) {
      if (sum != 0) return false;
    } else if (sign[i][index] < 0) {
      if (sum >= 0) return false;
    } else if (sign[i][index] > 0) {
      if (sum <= 0) return false;
    }
  }

  return true;
}

bool guess(int index) {
  if (index == N) return true;

  if (sign[index][index] == 0) {
    result[index] = 0;
    return check(index) && guess(index + 1);
  }

  for (int i = 1; i <= 10; i++) {
    result[index] = sign[index][index] * i;
    if (check(index) && guess(index + 1)) return true;
  }

  return false;
}

int main() {
  cin >> N;

  string s;
  cin >> s;

  int index = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (s[index] == '0')
        sign[i][j] = 0;
      else if (s[index] == '+')
        sign[i][j] = 1;
      else
        sign[i][j] = -1;

      index++;
    }
  }

  guess(0);

  for (int i = 0; i < N; i++) {
    cout << result[i] << ' ';
  }
}