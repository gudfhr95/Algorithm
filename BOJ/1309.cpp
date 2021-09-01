#include <iostream>

using namespace std;

int CACHE[100001][3];

int main() {
  int N;

  cin >> N;

  CACHE[1][0] = CACHE[1][1] = CACHE[1][2] = 1;

  for (int i = 2; i <= N; i++) {
    CACHE[i][0] = (CACHE[i - 1][1] + CACHE[i - 1][2]) % 9901;
    CACHE[i][1] = (CACHE[i - 1][0] + CACHE[i - 1][2]) % 9901;
    CACHE[i][2] = (CACHE[i - 1][0] + CACHE[i - 1][1] + CACHE[i - 1][2]) % 9901;
  }

  cout << (CACHE[N][0] + CACHE[N][1] + CACHE[N][2]) % 9901;
}