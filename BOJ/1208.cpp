#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, S;

int main() {
  cin >> N >> S;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int m = N / 2;
  int n = N - m;

  vector<int> first(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    for (int k = 0; k < n; k++) {
      if (i & (1 << k)) {
        first[i] += A[k];
      }
    }
  }

  vector<int> second(1 << m);
  for (int i = 0; i < (1 << m); i++) {
    for (int k = 0; k < m; k++) {
      if (i & (1 << k)) {
        second[i] += A[k + n];
      }
    }
  }

  sort(first.begin(), first.end());
  sort(second.begin(), second.end(), greater<>());

  n = (1 << n);
  m = (1 << m);

  int i = 0;
  int j = 0;
  long long result = 0;
  while (i < n && j < m) {
    if (first[i] + second[j] == S) {
      long long c1 = 1;
      long long c2 = 1;

      i++;
      j++;

      while (i < n && first[i] == first[i - 1]) {
        c1 += 1;
        i += 1;
      }
      while (j < m && second[j] == second[j - 1]) {
        c2 += 1;
        j += 1;
      }
      result += c1 * c2;
    } else if (first[i] + second[j] < S) {
      i += 1;
    } else {
      j += 1;
    }
  }

  if (S == 0) {
    result -= 1;
  }

  cout << result;
}