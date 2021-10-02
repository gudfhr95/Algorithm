#include <iostream>

using namespace std;

int T[16];
int P[16];

int counsel(int day, int total, int n) {
  if (day > n + 1) return -987654321;

  if (day == n + 1) return total;

  int result = -987654321;
  result = max(result, counsel(day + 1, total, n));
  result = max(result, counsel(day + T[day], total + P[day], n));

  return result;
}

int main() {
  int N;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> T[i] >> P[i];
  }

  cout << counsel(1, 0, N);
}