#include <iostream>

using namespace std;

int A[500000];
int B[500000];

long long solve(int start, int end) {
  if (start == end) return 0;

  int mid = (start + end) / 2;

  long long result = solve(start, mid) + solve(mid + 1, end);

  int i = start;
  int j = mid + 1;
  int k = 0;
  while (i <= mid || j <= end) {
    if (i <= mid && (j > end || A[i] <= A[j])) {
      B[k++] = A[i++];
    } else {
      result += (long long)(mid - i + 1);
      B[k++] = A[j++];
    }
  }

  for (int i = start; i <= end; i++) {
    A[i] = B[i - start];
  }

  return result;
}

int main() {
  int N;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  long long result = solve(0, N - 1);

  printf("%lld", result);
}