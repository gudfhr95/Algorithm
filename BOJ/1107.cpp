#include <cstring>
#include <iostream>

using namespace std;

bool button[10];

bool isAvailable(int n) {
  if (n == 0) return button[n];

  while (n > 0) {
    int index = n % 10;

    if (!button[index]) return false;

    n /= 10;
  }

  return true;
}

int press(int n) {
  int result = abs(n - 100);

  for (int i = 0; i <= 999999; i++) {
    if (!isAvailable(i)) continue;

    result = min(result, (int)(abs(n - i) + to_string(i).length()));
  }

  return result;
}

int main() {
  int N, M, b;

  memset(button, true, sizeof(button));

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> b;
    button[b] = false;
  }

  cout << press(N);
}