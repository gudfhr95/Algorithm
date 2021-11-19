#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int N[500000], M[500000];

bool search(int t) {
  int left = 0, right = n - 1;

  int mid;
  while (left <= right) {
    mid = (left + right) / 2;

    if (N[mid] == t) {
      return true;
    } else if (N[mid] > t) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return false;
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
    cout << search(M[i]) << ' ';
  }
}