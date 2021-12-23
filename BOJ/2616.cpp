#include <cstring>
#include <iostream>

using namespace std;

int N, M;
int A[50001];
int S[50001];
int d[50001][4];

int go(int index, int trains) {
  if (index >= N || trains == 0) {
    return 0;
  }

  int& ret = d[index][trains];

  if (ret != -1) return ret;

  ret = S[index + M - 1] - S[index - 1];
  ret += go(index + M, trains - 1);
  
  ret = max(ret, go(index + 1, trains));

  return ret;
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];

    S[i] = S[i - 1] + A[i];
  }

  cin >> M;

  memset(d, -1, sizeof(d));

  cout << go(1, 3);
}
