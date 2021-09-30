#include <algorithm>
#include <iostream>

using namespace std;

int seq[8];
bool c[8];
int a[8];

void permutation(int index, int n, int m) {
  if (index == m) {
    for (int i = 0; i < m; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++) {
    if (index > 0 && a[index - 1] > seq[i]) continue;

    c[i] = true;

    a[index] = seq[i];
    permutation(index + 1, n, m);
    c[i] = false;
  }
}

int main() {
  int N, M;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
  }

  sort(seq, seq + N);

  permutation(0, N, M);
}