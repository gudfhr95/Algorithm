#include <iostream>
#include <vector>

using namespace std;

int N;

void swap(vector<int> &a, int index) {
  for (int i = index - 1; i <= index + 1; i++) {
    if (0 <= i && i < N) {
      a[i] = 1 - a[i];
    }
  }
}

pair<bool, int> solve(vector<int> a, vector<int> b) {
  int result = 0;

  for (int i = 0; i < N - 1; i++) {
    if (a[i] != b[i]) {
      swap(a, i + 1);
      result++;
    }
  }

  if (a == b) {
    return {true, result};
  } else {
    return {false, result};
  }
}

int main() {
  scanf("%d", &N);

  vector<int> A(N);
  vector<int> B(N);

  for (int i = 0; i < N; i++) {
    scanf("%1d", &A[i]);
  }

  for (int i = 0; i < N; i++) {
    scanf("%1d", &B[i]);
  }

  auto result1 = solve(A, B);

  swap(A, 0);
  auto result2 = solve(A, B);

  if (result2.first) {
    result2.second += 1;
  }

  if (result1.first && result2.first) {
    printf("%d\n", min(result1.second, result2.second));
  } else if (result1.first) {
    printf("%d\n", result1.second);
  } else if (result2.first) {
    printf("%d\n", result2.second);
  } else {
    printf("-1\n");
  }
}