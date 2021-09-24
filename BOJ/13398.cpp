#include <algorithm>
#include <iostream>

using namespace std;

int A[100000];
int DL[100000];
int DR[100000];

void dl(int n) {
  DL[0] = A[0];

  for (int i = 0; i < n; i++) {
    DL[i] = max(A[i], DL[i - 1] + A[i]);
  }
}

void dr(int n) {
  DR[n - 1] = A[n - 1];

  for (int i = n - 1; i >= 0; i--) {
    DR[i] = max(A[i], DR[i + 1] + A[i]);
  }
}

int main() {
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  dl(n);
  dr(n);

  int result = -987654321;
  for (int i = 0; i < n; i++) {
    result = max(result, DL[i]);
  }
  for (int i = 1; i < n - 1; i++) {
    result = max(result, DL[i - 1] + DR[i + 1]);
  }
  cout << result;
}