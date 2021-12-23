#include <iostream>

using namespace std;

int N, K;
bool d[31][31][31][436];
char result[32];

bool go(int i, int a, int b, int p) {
  if (i == N) {
    if (p == K)
      return true;
    else
      return false;
  }

  if(d[i][a][b][p]) return false;

  d[i][a][b][p] = true;

  result[i] = 'A';
  if(go(i+1, a+1, b, p)) return true;

  result[i] = 'B';
  if(go(i+1, a, b+1, p+a)) return true;

  result[i] = 'C';
  if(go(i+1, a, b, p+a+b)) return true;

  return false;
}

int main() {
  cin >> N >> K;

  if (go(0, 0, 0, 0)) {
    cout << result << '\n';
  } else {
    cout << -1 << '\n';
  }
}
