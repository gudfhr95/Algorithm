#include <iostream>

using namespace std;

int d[100][100];

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> d[i][j];
    }
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (d[i][k] != 0 && d[k][j] != 0) {
          d[i][j] = 1;
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << d[i][j] << ' ';
    }
    cout << '\n';
  }
}