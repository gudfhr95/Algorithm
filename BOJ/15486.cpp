#include <iostream>

using namespace std;

int N;
int T[1500001];
int P[1500001];
int d[1500001];

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> T[i] >> P[i];
  }

  for (int i = 1; i <= N; i++) {
    d[i + T[i]] = max(d[i + T[i]], d[i] + P[i]);
    d[i + 1] = max(d[i + 1], d[i]);
  }

  cout << d[N + 1];
}
