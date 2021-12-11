#include <iostream>

using namespace std;

long long A, B;
int result = -1;

void go(long long a, int cnt) {
  if (a == B) {
    if (result == -1) {
      result = cnt;
    } else {
      result = min(result, cnt);
    }
  }

  if (a > 1000000000) {
    return;
  }

  go(a * 2, cnt + 1);
  go(a * 10 + 1, cnt + 1);
}

int main() {
  cin >> A >> B;

  go(A, 1);

  cout << result;
}