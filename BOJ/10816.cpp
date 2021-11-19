#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int N[500000], M[500000];

int lowerBound(int target) {
  int result = -1;

  int left = 0, right = n - 1;
  int mid;

  while (left <= right) {
    mid = (left + right) / 2;

    if (N[mid] == target) {
      result = mid;
      right = mid - 1;
    } else if (N[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return result;
}

int upperBound(int target) {
  int result = -1;

  int left = 0, right = n - 1;
  int mid;

  while (left <= right) {
    mid = (left + right) / 2;

    if (N[mid] == target) {
      result = mid + 1;
      left = mid + 1;
    } else if (N[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return result;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }

  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> M[i];
  }

  sort(N, N + n);

  for (int i = 0; i < m; i++) {
    int lb = lowerBound(M[i]);
    int ub = upperBound(M[i]);

    if (lb == -1 || ub == -1) {
      cout << 0;
    } else {
      cout << ub - lb;
    }
    cout << ' ';
  }
}